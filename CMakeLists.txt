cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(mozjs)

#####################################################################
## Options
option(MOZJS_THREADSAFE "Build SpiderMonkey with thread-safety" ON)
option(MOZJS_ENABLE_ION "Build SpiderMonkey with method-jit" OFF)
option(MOZJS_STATIC_LIB "Build SpiderMonkey as a static library" OFF)
option(MOZJS_STATIC_RTL "Link msvc runtime libraries statically" OFF)

#####################################################################
## MOZILLA_SOURCE must be set to the path of mozilla-unified source
option(MOZILLA_SOURCE "The location of mozilla source code" "")
message(STATUS "Mozilla source location: ${MOZILLA_SOURCE}")

#####################################################################
## Compile definitions
add_definitions(-DJS_DEFAULT_JITREPORT_GRANULARITY=3)
add_definitions(-DWIN32)
add_definitions(-DWIN32_LEAN_AND_MEAN)
add_definitions(-DXP_WIN)
add_definitions(-DWINVER=0x601)

if(CMAKE_BUILD_TYPE MATCHES "^(D|d)ebug$")
  add_definitions(-DDEBUG -D_DEBUG)
else()
  add_definitions(-DNDEBUG -D_NDEBUG)
endif()

if(CMAKE_SIZEOF_VOID_P MATCHES 8)
  add_definitions(-D_AMD64_)
  set(TARGET_CPU "x86_64")
else()
  add_definitions(-D_X86_)
  set(TARGET_CPU "x86")
endif()

if(MOZJS_STATIC_LIB)
  set(LIBRARY_TYPE)
  set(LIBRARY_DIR lib)
  message(STATUS "Building static libraries")
  message(STATUS "Install directory ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR}")
else()
  set(LIBRARY_TYPE SHARED)
  set(LIBRARY_DIR bin)
  message(STATUS "Building dynamic libraries")
  message(STATUS "Install directory ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR}")
endif()

if(MOZJS_THREADSAFE)
  set(JS_THREADSAFE ON)
  message(STATUS "Building with thread-safety")
endif()

# TODO: Properly define version
add_definitions(-DMOZILLA_VERSION="0.0")

#####################################################################
## example (Executable)
#####################################################################
add_subdirectory(example)

#####################################################################
## Choosing version
## TODO: Support more ESR versions, goal is all available as boomarks
## in the Mercurial repository
add_subdirectory(esr24)

