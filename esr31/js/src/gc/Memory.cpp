/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * vim: set ts=8 sts=4 et sw=4 tw=99:
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "gc/Memory.h"

#include "js/HeapAPI.h"
#include "vm/Runtime.h"

using namespace js;
using namespace js::gc;

static bool
DecommitEnabled(JSRuntime* rt)
{
    return rt->gcSystemPageSize == ArenaSize;
}

#if defined(XP_WIN)
#include "jswin.h"
#include <psapi.h>

void
gc::InitMemorySubsystem(JSRuntime* rt)
{
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    rt->gcSystemPageSize = sysinfo.dwPageSize;
    rt->gcSystemAllocGranularity = sysinfo.dwAllocationGranularity;
}

void*
gc::MapAlignedPages(JSRuntime* rt, size_t size, size_t alignment)
{
    JS_ASSERT(size >= alignment);
    JS_ASSERT(size % alignment == 0);
    JS_ASSERT(size % rt->gcSystemPageSize == 0);
    JS_ASSERT(alignment % rt->gcSystemAllocGranularity == 0);

    /* Special case: If we want allocation alignment, no further work is needed. */
    if (alignment == rt->gcSystemAllocGranularity) {
        return VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    }

    /*
     * Windows requires that there be a 1:1 mapping between VM allocation
     * and deallocation operations.  Therefore, take care here to acquire the
     * final result via one mapping operation.  This means unmapping any
     * preliminary result that is not correctly aligned.
     */
    void* p = nullptr;
    while (!p) {
        /*
         * Over-allocate in order to map a memory region that is definitely
         * large enough, then deallocate and allocate again the correct size,
         * within the over-sized mapping.
         *
         * Since we're going to unmap the whole thing anyway, the first
         * mapping doesn't have to commit pages.
         */
        size_t reserveSize = size + alignment - rt->gcSystemPageSize;
        p = VirtualAlloc(nullptr, reserveSize, MEM_RESERVE, PAGE_READWRITE);
        if (!p)
            return nullptr;
        void* chunkStart = (void*)AlignBytes(uintptr_t(p), alignment);
        UnmapPages(rt, p, reserveSize);
        p = VirtualAlloc(chunkStart, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        /* Failure here indicates a race with another thread, so try again. */
    }

    JS_ASSERT(uintptr_t(p) % alignment == 0);
    return p;
}

void
gc::UnmapPages(JSRuntime* rt, void* p, size_t size)
{
    JS_ALWAYS_TRUE(VirtualFree(p, 0, MEM_RELEASE));
}

bool
gc::MarkPagesUnused(JSRuntime* rt, void* p, size_t size)
{
    if (!DecommitEnabled(rt))
        return true;

    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
    LPVOID p2 = VirtualAlloc(p, size, MEM_RESET, PAGE_READWRITE);
    return p2 == p;
}

bool
gc::MarkPagesInUse(JSRuntime* rt, void* p, size_t size)
{
    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
    return true;
}

size_t
gc::GetPageFaultCount()
{
    PROCESS_MEMORY_COUNTERS pmc;
    if (!GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
        return 0;
    return pmc.PageFaultCount;
}

void*
gc::AllocateMappedContent(int fd, size_t offset, size_t length, size_t alignment)
{
    // TODO: Bug 988813 - Support memory mapped array buffer for Windows platform.
    return nullptr;
}

// Deallocate mapped memory for object.
void
gc::DeallocateMappedContent(void* p, size_t length)
{
    // TODO: Bug 988813 - Support memory mapped array buffer for Windows platform.
}

#elif defined(SOLARIS)

#include <sys/mman.h>
#include <unistd.h>

#ifndef MAP_NOSYNC
# define MAP_NOSYNC 0
#endif

void
gc::InitMemorySubsystem(JSRuntime* rt)
{
    rt->gcSystemPageSize = rt->gcSystemAllocGranularity = size_t(sysconf(_SC_PAGESIZE));
}

void*
gc::MapAlignedPages(JSRuntime* rt, size_t size, size_t alignment)
{
    JS_ASSERT(size >= alignment);
    JS_ASSERT(size % alignment == 0);
    JS_ASSERT(size % rt->gcSystemPageSize == 0);
    JS_ASSERT(alignment % rt->gcSystemAllocGranularity == 0);

    int prot = PROT_READ | PROT_WRITE;
    int flags = MAP_PRIVATE | MAP_ANON | MAP_ALIGN | MAP_NOSYNC;

    void* p = mmap((caddr_t)alignment, size, prot, flags, -1, 0);
    if (p == MAP_FAILED)
        return nullptr;
    return p;
}

void
gc::UnmapPages(JSRuntime* rt, void* p, size_t size)
{
    JS_ALWAYS_TRUE(0 == munmap((caddr_t)p, size));
}

bool
gc::MarkPagesUnused(JSRuntime* rt, void* p, size_t size)
{
    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
    return true;
}

bool
gc::MarkPagesInUse(JSRuntime* rt, void* p, size_t size)
{
    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
    return true;
}

size_t
gc::GetPageFaultCount()
{
    return 0;
}

void*
gc::AllocateMappedContent(int fd, size_t offset, size_t length, size_t alignment)
{
    // Not implemented.
    return nullptr;
}

// Deallocate mapped memory for object.
void
gc::DeallocateMappedContent(void* p, size_t length)
{
    // Not implemented.
}

#elif defined(XP_UNIX)

#include <algorithm>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void
gc::InitMemorySubsystem(JSRuntime* rt)
{
    rt->gcSystemPageSize = rt->gcSystemAllocGranularity = size_t(sysconf(_SC_PAGESIZE));
}

static inline void*
MapMemory(size_t length, int prot, int flags, int fd, off_t offset)
{
#if defined(__ia64__)
    /*
     * The JS engine assumes that all allocated pointers have their high 17 bits clear,
     * which ia64's mmap doesn't support directly. However, we can emulate it by passing
     * mmap an "addr" parameter with those bits clear. The mmap will return that address,
     * or the nearest available memory above that address, providing a near-guarantee
     * that those bits are clear. If they are not, we return nullptr below to indicate
     * out-of-memory.
     *
     * The addr is chosen as 0x0000070000000000, which still allows about 120TB of virtual
     * address space.
     *
     * See Bug 589735 for more information.
     */
    void* region = mmap((void*)0x0000070000000000, length, prot, flags, fd, offset);
    if (region == MAP_FAILED)
        return MAP_FAILED;
    /*
     * If the allocated memory doesn't have its upper 17 bits clear, consider it
     * as out of memory.
     */
    if ((uintptr_t(region) + (length - 1)) & 0xffff800000000000) {
        JS_ALWAYS_TRUE(0 == munmap(region, length));
        return MAP_FAILED;
    }
    return region;
#else
    return mmap(nullptr, length, prot, flags, fd, offset);
#endif
}

void*
gc::MapAlignedPages(JSRuntime* rt, size_t size, size_t alignment)
{
    JS_ASSERT(size >= alignment);
    JS_ASSERT(size % alignment == 0);
    JS_ASSERT(size % rt->gcSystemPageSize == 0);
    JS_ASSERT(alignment % rt->gcSystemAllocGranularity == 0);

    int prot = PROT_READ | PROT_WRITE;
    int flags = MAP_PRIVATE | MAP_ANON;

    /* Special case: If we want page alignment, no further work is needed. */
    if (alignment == rt->gcSystemAllocGranularity) {
        void* region = MapMemory(size, prot, flags, -1, 0);
        if (region == MAP_FAILED)
            return nullptr;
        return region;
    }

    /* Overallocate and unmap the region's edges. */
    size_t reqSize = Min(size + 2 * alignment, 2 * size);
    void* region = MapMemory(reqSize, prot, flags, -1, 0);
    if (region == MAP_FAILED)
        return nullptr;

    uintptr_t regionEnd = uintptr_t(region) + reqSize;
    uintptr_t offset = uintptr_t(region) % alignment;
    JS_ASSERT(offset < reqSize - size);

    void* front = (void*)AlignBytes(uintptr_t(region), alignment);
    void* end = (void*)(uintptr_t(front) + size);
    if (front != region)
        JS_ALWAYS_TRUE(0 == munmap(region, alignment - offset));
    if (uintptr_t(end) != regionEnd)
        JS_ALWAYS_TRUE(0 == munmap(end, regionEnd - uintptr_t(end)));

    JS_ASSERT(uintptr_t(front) % alignment == 0);
    return front;
}

void
gc::UnmapPages(JSRuntime* rt, void* p, size_t size)
{
    JS_ALWAYS_TRUE(0 == munmap(p, size));
}

bool
gc::MarkPagesUnused(JSRuntime* rt, void* p, size_t size)
{
    if (!DecommitEnabled(rt))
        return false;

    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
    int result = madvise(p, size, MADV_DONTNEED);
    return result != -1;
}

bool
gc::MarkPagesInUse(JSRuntime* rt, void* p, size_t size)
{
    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
    return true;
}

size_t
gc::GetPageFaultCount()
{
    struct rusage usage;
    int err = getrusage(RUSAGE_SELF, &usage);
    if (err)
        return 0;
    return usage.ru_majflt;
}

void*
gc::AllocateMappedContent(int fd, size_t offset, size_t length, size_t alignment)
{
#define NEED_PAGE_ALIGNED 0
    size_t pa_start; // Page aligned starting
    size_t pa_end; // Page aligned ending
    size_t pa_size; // Total page aligned size
    size_t page_size = sysconf(_SC_PAGESIZE); // Page size
    struct stat st;
    uint8_t* buf;

    // Make sure file exists and do sanity check for offset and size.
    if (fstat(fd, &st) < 0 || offset >= (size_t) st.st_size ||
        length == 0 || length > (size_t) st.st_size - offset)
        return nullptr;

    // Check for minimal alignment requirement.
#if NEED_PAGE_ALIGNED
    alignment = std::max(alignment, page_size);
#endif
    if (offset & (alignment - 1))
        return nullptr;

    // Page aligned starting of the offset.
    pa_start = offset & ~(page_size - 1);
    // Calculate page aligned ending by adding one page to the page aligned
    // starting of data end position(offset + length - 1).
    pa_end = ((offset + length - 1) & ~(page_size - 1)) + page_size;
    pa_size = pa_end - pa_start;

    // Ask for a continuous memory location.
    buf = (uint8_t*) MapMemory(pa_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (buf == MAP_FAILED)
        return nullptr;

    buf = (uint8_t*) mmap(buf, pa_size, PROT_READ | PROT_WRITE,
                           MAP_PRIVATE | MAP_FIXED, fd, pa_start);
    if (buf == MAP_FAILED)
        return nullptr;

    // Reset the data before target file, which we don't need to see.
    memset(buf, 0, offset - pa_start);

    // Reset the data after target file, which we don't need to see.
    memset(buf + (offset - pa_start) + length, 0, pa_end - (offset + length));

    return buf + (offset - pa_start);
}

void
gc::DeallocateMappedContent(void* p, size_t length)
{
    void* pa_start; // Page aligned starting
    size_t page_size = sysconf(_SC_PAGESIZE); // Page size
    size_t total_size; // Total allocated size

    pa_start = (void*)(uintptr_t(p) & ~(page_size - 1));
    total_size = ((uintptr_t(p) + length) & ~(page_size - 1)) + page_size - uintptr_t(pa_start);
    munmap(pa_start, total_size);
}

#else
#error "Memory mapping functions are not defined for your OS."
#endif
