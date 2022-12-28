# BUG: JSGC_INCREMENTAL must be defined because it is used without checking if defined in jsgc.cpp#4511
add_definitions(-DJSGC_INCREMENTAL)

#####################################################################
## SpiderMonkey (Library)
#####################################################################
set(JS_SOURCE_DIR ${MOZILLA_SOURCE}/js/src)
# Listed in the same order as in js/src/moz.build
# Early version of js did not provide full path to source files
set(JS_SRCS
  ${JS_SOURCE_DIR}/vm/ArgumentsObject.cpp
  ${JS_SOURCE_DIR}/frontend/BytecodeCompiler.cpp
  ${JS_SOURCE_DIR}/frontend/BytecodeEmitter.cpp
  ${JS_SOURCE_DIR}/vm/CharacterEncoding.cpp
  ${JS_SOURCE_DIR}/vm/DateTime.cpp
  ${JS_SOURCE_DIR}/vm/Debugger.cpp
  ${JS_SOURCE_DIR}/builtin/Eval.cpp
  ${JS_SOURCE_DIR}/assembler/jit/ExecutableAllocator.cpp
  ${JS_SOURCE_DIR}/frontend/FoldConstants.cpp
  ${JS_SOURCE_DIR}/vm/ForkJoin.cpp
  ${JS_SOURCE_DIR}/vm/GlobalObject.cpp
  ${JS_SOURCE_DIR}/vm/Interpreter.cpp
  ${JS_SOURCE_DIR}/builtin/Intl.cpp
  ${JS_SOURCE_DIR}/gc/Iteration.cpp
  ${JS_SOURCE_DIR}/ds/LifoAlloc.cpp
  ${JS_SOURCE_DIR}/builtin/MapObject.cpp
  ${JS_SOURCE_DIR}/gc/Marking.cpp
  ${JS_SOURCE_DIR}/gc/Memory.cpp
  ${JS_SOURCE_DIR}/builtin/Module.cpp
  ${JS_SOURCE_DIR}/vm/Monitor.cpp
  ${JS_SOURCE_DIR}/frontend/NameFunctions.cpp
  ${JS_SOURCE_DIR}/gc/Nursery.cpp
  ${JS_SOURCE_DIR}/builtin/Object.cpp
  ${JS_SOURCE_DIR}/vm/ObjectImpl.cpp
  ${JS_SOURCE_DIR}/yarr/PageBlock.cpp
  ${JS_SOURCE_DIR}/builtin/ParallelArray.cpp
  ${JS_SOURCE_DIR}/frontend/ParseMaps.cpp
  ${JS_SOURCE_DIR}/frontend/ParseNode.cpp
  ${JS_SOURCE_DIR}/frontend/Parser.cpp
  ${JS_SOURCE_DIR}/vm/Probes.cpp
  ${JS_SOURCE_DIR}/builtin/Profilers.cpp
  ${JS_SOURCE_DIR}/vm/PropertyKey.cpp
  ${JS_SOURCE_DIR}/builtin/RegExp.cpp
  ${JS_SOURCE_DIR}/vm/RegExpObject.cpp
  ${JS_SOURCE_DIR}/vm/RegExpStatics.cpp
  ${JS_SOURCE_DIR}/gc/RootMarking.cpp
  ${JS_SOURCE_DIR}/vm/SPSProfiler.cpp
  ${JS_SOURCE_DIR}/vm/ScopeObject.cpp
  ${JS_SOURCE_DIR}/vm/SelfHosting.cpp
  ${JS_SOURCE_DIR}/vm/Shape.cpp
  ${JS_SOURCE_DIR}/vm/Stack.cpp
  ${JS_SOURCE_DIR}/gc/Statistics.cpp
  ${JS_SOURCE_DIR}/gc/StoreBuffer.cpp
  ${JS_SOURCE_DIR}/vm/String.cpp
  ${JS_SOURCE_DIR}/vm/StringBuffer.cpp
  ${JS_SOURCE_DIR}/builtin/TestingFunctions.cpp
  ${JS_SOURCE_DIR}/vm/ThreadPool.cpp
  ${JS_SOURCE_DIR}/frontend/TokenStream.cpp
  ${JS_SOURCE_DIR}/vm/Unicode.cpp
  ${JS_SOURCE_DIR}/gc/Verifier.cpp
  ${JS_SOURCE_DIR}/vm/Xdr.cpp
  ${JS_SOURCE_DIR}/yarr/YarrCanonicalizeUCS2.cpp
  ${JS_SOURCE_DIR}/yarr/YarrInterpreter.cpp
  ${JS_SOURCE_DIR}/yarr/YarrPattern.cpp
  ${JS_SOURCE_DIR}/yarr/YarrSyntaxChecker.cpp
  ${JS_SOURCE_DIR}/gc/Zone.cpp
  
  ${JS_SOURCE_DIR}/jsalloc.cpp
  ${JS_SOURCE_DIR}/jsanalyze.cpp
  ${JS_SOURCE_DIR}/jsapi.cpp
  ${JS_SOURCE_DIR}/jsarray.cpp
  ${JS_SOURCE_DIR}/jsatom.cpp
  ${JS_SOURCE_DIR}/jsbool.cpp
  ${JS_SOURCE_DIR}/jsclone.cpp
  ${JS_SOURCE_DIR}/jscntxt.cpp
  ${JS_SOURCE_DIR}/jscompartment.cpp
  ${JS_SOURCE_DIR}/jscrashreport.cpp
  ${JS_SOURCE_DIR}/jsdate.cpp
  ${JS_SOURCE_DIR}/jsdbgapi.cpp
  ${JS_SOURCE_DIR}/jsdtoa.cpp
  ${JS_SOURCE_DIR}/jsexn.cpp
  ${JS_SOURCE_DIR}/jsfriendapi.cpp
  ${JS_SOURCE_DIR}/jsfun.cpp
  ${JS_SOURCE_DIR}/jsgc.cpp
  ${JS_SOURCE_DIR}/jsinfer.cpp
  ${JS_SOURCE_DIR}/jsiter.cpp
  ${JS_SOURCE_DIR}/jsmath.cpp
  ${JS_SOURCE_DIR}/jsmemorymetrics.cpp
  ${JS_SOURCE_DIR}/jsnativestack.cpp
  ${JS_SOURCE_DIR}/jsnum.cpp
  ${JS_SOURCE_DIR}/jsobj.cpp
  ${JS_SOURCE_DIR}/json.cpp
  ${JS_SOURCE_DIR}/jsonparser.cpp
  ${JS_SOURCE_DIR}/jsopcode.cpp
  ${JS_SOURCE_DIR}/perf/jsperf.cpp
  ${JS_SOURCE_DIR}/jsprf.cpp
  ${JS_SOURCE_DIR}/jspropertytree.cpp
  ${JS_SOURCE_DIR}/jsproxy.cpp
  ${JS_SOURCE_DIR}/jsreflect.cpp
  ${JS_SOURCE_DIR}/jsscript.cpp
  ${JS_SOURCE_DIR}/jsstr.cpp
  ${JS_SOURCE_DIR}/jstypedarray.cpp
  ${JS_SOURCE_DIR}/jsutil.cpp
  ${JS_SOURCE_DIR}/jswatchpoint.cpp
  ${JS_SOURCE_DIR}/jsweakmap.cpp
  ${JS_SOURCE_DIR}/jsworkers.cpp
  ${JS_SOURCE_DIR}/jswrapper.cpp
  ${JS_SOURCE_DIR}/prmjtime.cpp
  ${JS_SOURCE_DIR}/devtools/sharkctl.cpp)

if(MOZ_INSTRUMENTS)
  list(APPEND JS_SRCS
    ${JS_SOURCE_DIR}/devtools/Instrument.cpp)
endif()

if(ENABLE_TRACE_LOGGING)
  list(APPEND JS_SRCS
    ${JS_SOURCE_DIR}/TraceLogging.cpp)
endif()

if(MOZJS_ENABLE_ION)
  list(APPEND JS_SRCS
    ${JS_SOURCE_DIR}/jit/AliasAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/AsmJS.cpp
    ${JS_SOURCE_DIR}/jit/AsmJSLink.cpp
    ${JS_SOURCE_DIR}/jit/ASMJSSignalHandlers.cpp
    ${JS_SOURCE_DIR}/jit/BacktracingAllocator.cpp
    ${JS_SOURCE_DIR}/jit/Bailouts.cpp
    ${JS_SOURCE_DIR}/jit/BaselineBailouts.cpp
    ${JS_SOURCE_DIR}/jit/shared/BaselineCompiler-shared.cpp
    ${JS_SOURCE_DIR}/jit/BaselineCompiler.cpp
    ${JS_SOURCE_DIR}/jit/BaselineFrame.cpp
    ${JS_SOURCE_DIR}/jit/BaselineFrameInfo.cpp
    ${JS_SOURCE_DIR}/jit/BaselineIC.cpp
    ${JS_SOURCE_DIR}/jit/BaselineInspector.cpp
    ${JS_SOURCE_DIR}/jit/BaselineJIT.cpp
    ${JS_SOURCE_DIR}/jit/BitSet.cpp
    ${JS_SOURCE_DIR}/jit/BytecodeAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/C1Spewer.cpp
    ${JS_SOURCE_DIR}/jit/shared/CodeGenerator-shared.cpp
    ${JS_SOURCE_DIR}/jit/CodeGenerator.cpp
    ${JS_SOURCE_DIR}/jit/EdgeCaseAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/EffectiveAddressAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/Ion.cpp
    ${JS_SOURCE_DIR}/jit/IonAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/IonBuilder.cpp
    ${JS_SOURCE_DIR}/jit/IonCaches.cpp
    ${JS_SOURCE_DIR}/jit/IonFrames.cpp
    ${JS_SOURCE_DIR}/jit/IonMacroAssembler.cpp
    ${JS_SOURCE_DIR}/jit/IonSpewer.cpp
    ${JS_SOURCE_DIR}/jit/JSONSpewer.cpp
    ${JS_SOURCE_DIR}/jit/PerfSpewer.cpp
    ${JS_SOURCE_DIR}/jit/LICM.cpp
    ${JS_SOURCE_DIR}/jit/LIR.cpp
    ${JS_SOURCE_DIR}/jit/LinearScan.cpp
    ${JS_SOURCE_DIR}/jit/LiveRangeAllocator.cpp
    ${JS_SOURCE_DIR}/jit/shared/Lowering-shared.cpp
    ${JS_SOURCE_DIR}/jit/Lowering.cpp
    ${JS_SOURCE_DIR}/jit/MCallOptimize.cpp
    ${JS_SOURCE_DIR}/jit/MIR.cpp
    ${JS_SOURCE_DIR}/jit/MIRGraph.cpp
    ${JS_SOURCE_DIR}/jit/MoveResolver.cpp
    ${JS_SOURCE_DIR}/jit/ParallelArrayAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/ParallelFunctions.cpp
    ${JS_SOURCE_DIR}/jit/RangeAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/RegisterAllocator.cpp
    ${JS_SOURCE_DIR}/jit/Safepoints.cpp
    ${JS_SOURCE_DIR}/jit/Snapshots.cpp
    ${JS_SOURCE_DIR}/jit/StupidAllocator.cpp
    ${JS_SOURCE_DIR}/jit/TypePolicy.cpp
    ${JS_SOURCE_DIR}/jit/UnreachableCodeElimination.cpp
    ${JS_SOURCE_DIR}/jit/VMFunctions.cpp
    ${JS_SOURCE_DIR}/jit/ValueNumbering.cpp)

  if(TARGET_CPU MATCHES "^86$")
    list(APPEND JS_SRCS
      ${JS_SOURCE_DIR}/jit/shared/Assembler-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/BaselineCompiler-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/BaselineIC-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/CodeGenerator-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/IonFrames-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/Lowering-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/MoveEmitter-x86-shared.cpp)

    if(TARGET_CPU MATCHES "^x86_64$")
      list(APPEND JS_SRCS
        ${JS_SOURCE_DIR}/jit/x64/Assembler-x64.cpp
        ${JS_SOURCE_DIR}/jit/x64/Bailouts-x64.cpp
        ${JS_SOURCE_DIR}/jit/x64/BaselineCompiler-x64.cpp
        ${JS_SOURCE_DIR}/jit/x64/BaselineIC-x64.cpp
        ${JS_SOURCE_DIR}/jit/x64/CodeGenerator-x64.cpp
        ${JS_SOURCE_DIR}/jit/x64/Lowering-x64.cpp
        ${JS_SOURCE_DIR}/jit/x64/MacroAssembler-x64.cpp
        ${JS_SOURCE_DIR}/jit/x64/Trampoline-x64.cpp)
    else()
      list(APPEND JS_SRCS
        ${JS_SOURCE_DIR}/jit/x86/Assembler-x86.cpp
        ${JS_SOURCE_DIR}/jit/x86/Bailouts-x86.cpp
        ${JS_SOURCE_DIR}/jit/x86/BaselineCompiler-x86.cpp
        ${JS_SOURCE_DIR}/jit/x86/BaselineIC-x86.cpp
        ${JS_SOURCE_DIR}/jit/x86/CodeGenerator-x86.cpp
        ${JS_SOURCE_DIR}/jit/x86/Lowering-x86.cpp
        ${JS_SOURCE_DIR}/jit/x86/MacroAssembler-x86.cpp
        ${JS_SOURCE_DIR}/jit/x86/Trampoline-x86.cpp)
    endif()
  endif()
endif()

# line 294, actually if-statement but we only compile on windows
list(APPEND JS_SRCS
  ${JS_SOURCE_DIR}/assembler/jit/ExecutableAllocatorWin.cpp
  ${JS_SOURCE_DIR}/yarr/OSAllocatorWin.cpp)

if(MOZJS_ENABLE_ION OR MOZJS_ENABLE_YARR_JIT)
  list(APPEND JS_SRCS
    ${JS_SOURCE_DIR}/assembler/assembler/ASMAssembler.cpp
    ${JS_SOURCE_DIR}/assembler/assembler/MacroAssemblerASM.cpp
    ${JS_SOURCE_DIR}/assembler/assembler/MacroAssemblerX86Common.cpp)
endif()

if(MOZJS_ENABLE_YARR_JIT)
  list(APPEND JS_SRCS
    ${JS_SOURCE_DIR}/yarr/YarrJIT.cpp)
endif()

if(MOZJS_HAS_CTYPES)
  list(APPEND JS_SRCS
    ${JS_SOURCE_DIR}/ctypes/CTypes.cpp
    ${JS_SOURCE_DIR}/ctypes/Library.cpp)
endif()

list(APPEND JS_SRCS
  ${JS_SOURCE_DIR}/perf/pm_stub.cpp)
## End source files
###############################################################################
## Begin static library
add_library(js ${LIBRARY_TYPE} ${JS_SRCS})
add_library(mozjs::js ALIAS js)

set(JS_PUBLIC_HDRS
  ${JS_SOURCE_DIR}/../public/Anchor.h
  ${JS_SOURCE_DIR}/../public/CallArgs.h
  ${JS_SOURCE_DIR}/../public/CharacterEncoding.h
  ${JS_SOURCE_DIR}/../public/Date.h
  ${JS_SOURCE_DIR}/../public/GCAPI.h
  ${JS_SOURCE_DIR}/../public/HashTable.h
  ${JS_SOURCE_DIR}/../public/HeapAPI.h
  ${JS_SOURCE_DIR}/../public/LegacyIntTypes.h
  ${JS_SOURCE_DIR}/../public/MemoryMetrics.h
  ${JS_SOURCE_DIR}/../public/PropertyKey.h
  ${JS_SOURCE_DIR}/../public/RequiredDefines.h
  ${JS_SOURCE_DIR}/../public/RootingAPI.h
  ${JS_SOURCE_DIR}/../public/TemplateLib.h
  ${JS_SOURCE_DIR}/../public/Utility.h
  ${JS_SOURCE_DIR}/../public/Value.h
  ${JS_SOURCE_DIR}/../public/Vector.h)

foreach(_header ${JS_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${CMAKE_CURRENT_BINARY_DIR}/include/js/${_header_file} COPYONLY)
endforeach()

set(JS_EXPORT_HDRS
  ${JS_SOURCE_DIR}/js.msg
  ${JS_SOURCE_DIR}/jsalloc.h
  ${JS_SOURCE_DIR}/jsapi.h
  ${JS_SOURCE_DIR}/jsclass.h
  ${JS_SOURCE_DIR}/jsclist.h
  ${JS_SOURCE_DIR}/jscpucfg.h
  ${JS_SOURCE_DIR}/jsdbgapi.h
  ${JS_SOURCE_DIR}/jsfriendapi.h
  ${JS_SOURCE_DIR}/jslock.h
  ${JS_SOURCE_DIR}/perf/jsperf.h
  ${JS_SOURCE_DIR}/jsprf.h
  ${JS_SOURCE_DIR}/jsprototypes.h
  ${JS_SOURCE_DIR}/jsproxy.h
  ${JS_SOURCE_DIR}/jsprvtd.h
  ${JS_SOURCE_DIR}/jspubtd.h
  ${JS_SOURCE_DIR}/jstypes.h
  ${JS_SOURCE_DIR}/jsutil.h
  ${JS_SOURCE_DIR}/jsversion.h
  ${JS_SOURCE_DIR}/jswrapper.h)

foreach(_header ${JS_EXPORT_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${CMAKE_CURRENT_BINARY_DIR}/include/${_header_file} COPYONLY)
endforeach()

add_dependencies(js host_jsoplengen)

target_include_directories(js
  PRIVATE
    # icu could be a separate library interface
    ${JS_SOURCE_DIR}/../../intl/icu/source/common
    ${JS_SOURCE_DIR}/../../intl/icu/source/i18n

    ${JS_SOURCE_DIR}
    ${JS_SOURCE_DIR}/assembler
    ${JS_SOURCE_DIR}/assembler/wtf
    ${JS_SOURCE_DIR}/assembler/jit
    ${JS_SOURCE_DIR}/builtin
    ${JS_SOURCE_DIR}/devtools
    ${JS_SOURCE_DIR}/ds
    ${JS_SOURCE_DIR}/frontend
    ${JS_SOURCE_DIR}/gc
    ${JS_SOURCE_DIR}/perf
    # DO NOT USE /vm HERE!!!
    #${JS_SOURCE_DIR}/vm
    ${JS_SOURCE_DIR}/yarr
  PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/include)

target_link_libraries(js PUBLIC mozjs::mfbt)
if(MOZJS_THREADSAFE)
  target_link_libraries(js PUBLIC mozjs::nspr winmm)
endif()

target_compile_definitions(js PUBLIC -DIMPL_MFBT)
if(MOZJS_STATIC_LIB)
  target_compile_definitions(js PUBLIC -DSTATIC_JS_API)
else()
  target_compile_definitions(js PRIVATE -DEXPORT_JS_API)
endif()

###############################################################################
## SpiderMonkey (Generate files)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/js-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/js-config.h)

add_executable(host_jskwgen ${JS_SOURCE_DIR}/jskwgen.cpp)

add_custom_command(
  OUTPUT jsautokw.h
  COMMAND host_jskwgen jsautokw.h
  DEPENDS host_jskwgen
  COMMENT "Generating jsautokw.h"
  VERBATIM)

set_source_files_properties(jsautokw.h PROPERTIES GENERATED TRUE)
target_sources(js PRIVATE jsautokw.h)

add_executable(host_jsoplengen ${JS_SOURCE_DIR}/jsoplengen.cpp)

add_custom_command(
  OUTPUT jsautooplen.h
  COMMAND host_jsoplengen jsautooplen.h
  DEPENDS host_jsoplengen
  COMMENT "Generating jsautooplen.h"
  VERBATIM)

set_source_files_properties(jsautooplen.h PROPERTIES GENERATED TRUE)
target_sources(js PRIVATE jsautooplen.h)

set(SELFHOSTING_SRCS
  ${JS_SOURCE_DIR}/builtin/Utilities.js
  ${JS_SOURCE_DIR}/builtin/Array.js
  ${JS_SOURCE_DIR}/builtin/Date.js
  ${JS_SOURCE_DIR}/builtin/Intl.js
  ${JS_SOURCE_DIR}/builtin/IntlData.js
  ${JS_SOURCE_DIR}/builtin/Number.js
  ${JS_SOURCE_DIR}/builtin/ParallelArray.js
  ${JS_SOURCE_DIR}/builtin/String.js)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.out.h
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  # HINT: /EP flag is required for MSVC C++ compiler to work
  # TODO: Automatically find python 2.7
  COMMAND C:/Python27/python.exe ${JS_SOURCE_DIR}/builtin/embedjs.py -DDEBUG -p "${CMAKE_CXX_COMPILER} /EP" -m ${JS_SOURCE_DIR}/js.msg -o ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.out.h -s ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.js ${SELFHOSTING_SRCS}
  DEPENDS ${SELFHOSTING_SRCS} ${JS_SOURCE_DIR}/js.msg
  COMMENT "Generating selfhosted.out.h"
  VERBATIM)

set_source_files_properties(selfhosted.out.h PROPERTIES GENERATED TRUE)
target_sources(js PRIVATE selfhosted.out.h)

###############################################################################
## Begin install directives
install(TARGETS js
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include"
  DESTINATION ${CMAKE_INSTALL_PREFIX})

#####################################################################
## mfbt (Library)
#####################################################################
set(MFBT_SOURCE_DIR ${MOZILLA_SOURCE}/mfbt)
set(MFBT_SRCS
  ${MFBT_SOURCE_DIR}/double-conversion/bignum.cc
  ${MFBT_SOURCE_DIR}/double-conversion/bignum-dtoa.cc
  ${MFBT_SOURCE_DIR}/double-conversion/cached-powers.cc
  ${MFBT_SOURCE_DIR}/double-conversion/diy-fp.cc
  ${MFBT_SOURCE_DIR}/double-conversion/double-conversion.cc
  ${MFBT_SOURCE_DIR}/double-conversion/fast-dtoa.cc
  ${MFBT_SOURCE_DIR}/double-conversion/fixed-dtoa.cc
  ${MFBT_SOURCE_DIR}/double-conversion/strtod.cc

  ${MFBT_SOURCE_DIR}/decimal/Decimal.cpp
  
  ${MFBT_SOURCE_DIR}/HashFunctions.cpp
  ${MFBT_SOURCE_DIR}/Poison.cpp
  ${MFBT_SOURCE_DIR}/SHA1.cpp)

add_library(mfbt ${LIBRARY_TYPE} ${MFBT_SRCS})
add_library(mozjs::mfbt ALIAS mfbt)

target_include_directories(mfbt
  PRIVATE
    ${MFBT_SOURCE_DIR}/decimal
    ${MFBT_SOURCE_DIR}
  PUBLIC
    ${MFBT_SOURCE_DIR}/double-conversion
    ${CMAKE_CURRENT_BINARY_DIR}/include)

target_compile_definitions(mfbt PUBLIC -DIMPL_MFBT)

install(TARGETS mfbt
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})

set(MFBT_PUBLIC_HDRS
  ${MFBT_SOURCE_DIR}/Assertions.h
  ${MFBT_SOURCE_DIR}/Atomics.h
  ${MFBT_SOURCE_DIR}/Attributes.h
  ${MFBT_SOURCE_DIR}/BloomFilter.h
  ${MFBT_SOURCE_DIR}/Casting.h
  ${MFBT_SOURCE_DIR}/Char16.h
  ${MFBT_SOURCE_DIR}/CheckedInt.h
  ${MFBT_SOURCE_DIR}/Compiler.h
  ${MFBT_SOURCE_DIR}/Constants.h
  ${MFBT_SOURCE_DIR}/DebugOnly.h
  ${MFBT_SOURCE_DIR}/Endian.h
  ${MFBT_SOURCE_DIR}/EnumSet.h
  ${MFBT_SOURCE_DIR}/FloatingPoint.h
  ${MFBT_SOURCE_DIR}/GuardObjects.h
  ${MFBT_SOURCE_DIR}/HashFunctions.h
  ${MFBT_SOURCE_DIR}/Likely.h
  ${MFBT_SOURCE_DIR}/LinkedList.h
  ${MFBT_SOURCE_DIR}/MathAlgorithms.h
  ${MFBT_SOURCE_DIR}/MemoryChecking.h
  ${MFBT_SOURCE_DIR}/MSStdInt.h
  ${MFBT_SOURCE_DIR}/NullPtr.h
  ${MFBT_SOURCE_DIR}/PodOperations.h
  ${MFBT_SOURCE_DIR}/Poison.h
  ${MFBT_SOURCE_DIR}/Range.h
  ${MFBT_SOURCE_DIR}/RangedPtr.h
  ${MFBT_SOURCE_DIR}/RefPtr.h
  ${MFBT_SOURCE_DIR}/Scoped.h
  ${MFBT_SOURCE_DIR}/SHA1.h
  ${MFBT_SOURCE_DIR}/SplayTree.h
  ${MFBT_SOURCE_DIR}/StandardInteger.h
  ${MFBT_SOURCE_DIR}/ThreadLocal.h
  ${MFBT_SOURCE_DIR}/TypedEnum.h
  ${MFBT_SOURCE_DIR}/Types.h
  ${MFBT_SOURCE_DIR}/TypeTraits.h
  ${MFBT_SOURCE_DIR}/Util.h
  ${MFBT_SOURCE_DIR}/WeakPtr.h)

foreach(_header ${MFBT_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${CMAKE_CURRENT_BINARY_DIR}/include/mozilla/${_header_file} COPYONLY)
endforeach()
configure_file(
  ${MFBT_SOURCE_DIR}/decimal/Decimal.h
  ${CMAKE_CURRENT_BINARY_DIR}/include/mozilla/decimal/Decimal.h
  COPYONLY)

install(FILES ${MFBT_PUBLIC_HDRS}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/mozilla)

#####################################################################
## libc (Library)
#####################################################################
set(LIBC_SOURCE_DIR ${MOZILLA_SOURCE}/nsprpub/lib/libc)
set(LIBC_SRCS
  ${LIBC_SOURCE_DIR}/src/plvrsion.c
  ${LIBC_SOURCE_DIR}/src/strlen.c
  ${LIBC_SOURCE_DIR}/src/strcpy.c
  ${LIBC_SOURCE_DIR}/src/strdup.c
  ${LIBC_SOURCE_DIR}/src/strcase.c
  ${LIBC_SOURCE_DIR}/src/strcat.c
  ${LIBC_SOURCE_DIR}/src/strcmp.c
  ${LIBC_SOURCE_DIR}/src/strchr.c
  ${LIBC_SOURCE_DIR}/src/strpbrk.c
  ${LIBC_SOURCE_DIR}/src/strstr.c
  ${LIBC_SOURCE_DIR}/src/strtok.c
  ${LIBC_SOURCE_DIR}/src/base64.c
  ${LIBC_SOURCE_DIR}/src/plerror.c
  ${LIBC_SOURCE_DIR}/src/plgetopt.c)

add_library(libc ${LIBC_SRCS})
add_library(mozjs::plc ALIAS libc)

target_include_directories(libc
  PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
    ${LIBC_SOURCE_DIR}/include)

target_link_libraries(libc PRIVATE mozjs::nspr)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/_pl_bld.h ${CMAKE_CURRENT_BINARY_DIR}/_pl_bld.h COPYONLY)
target_sources(libc PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/_pl_bld.h)

install(TARGETS libc
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})

#####################################################################
## nspr (Library)
#####################################################################
set(NSPR_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/nsprpub/pr)
set(NSPR_SRCS
  ${NSPR_SOURCE_DIR}/src/io/prdir.c
  ${NSPR_SOURCE_DIR}/src/io/prfile.c
  ${NSPR_SOURCE_DIR}/src/io/prio.c
  ${NSPR_SOURCE_DIR}/src/io/prfdcach.c
  ${NSPR_SOURCE_DIR}/src/io/prmwait.c
  ${NSPR_SOURCE_DIR}/src/io/priometh.c 
  ${NSPR_SOURCE_DIR}/src/io/pripv6.c
  ${NSPR_SOURCE_DIR}/src/io/prmapopt.c
  ${NSPR_SOURCE_DIR}/src/io/prlayer.c
  ${NSPR_SOURCE_DIR}/src/io/prlog.c
  ${NSPR_SOURCE_DIR}/src/io/prmmap.c
  ${NSPR_SOURCE_DIR}/src/io/prpolevt.c
  ${NSPR_SOURCE_DIR}/src/io/prprf.c
  ${NSPR_SOURCE_DIR}/src/io/prscanf.c
  ${NSPR_SOURCE_DIR}/src/io/prsocket.c
  ${NSPR_SOURCE_DIR}/src/io/prstdio.c

  ${NSPR_SOURCE_DIR}/src/linking/prlink.c

  ${NSPR_SOURCE_DIR}/src/malloc/prmalloc.c
  ${NSPR_SOURCE_DIR}/src/malloc/prmem.c

  ${NSPR_SOURCE_DIR}/src/md/windows/ntmisc.c
  ${NSPR_SOURCE_DIR}/src/md/windows/ntsec.c
  ${NSPR_SOURCE_DIR}/src/md/windows/ntsem.c
  ${NSPR_SOURCE_DIR}/src/md/windows/ntinrval.c
  ${NSPR_SOURCE_DIR}/src/md/windows/ntgc.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w95thred.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w95io.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w95cv.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w95sock.c
  ${NSPR_SOURCE_DIR}/src/md/windows/win32_errors.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w32ipcsem.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w32poll.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w32rng.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w32shm.c
  ${NSPR_SOURCE_DIR}/src/md/windows/w95dllmain.c
  ${NSPR_SOURCE_DIR}/src/md/prosdep.c

  ${NSPR_SOURCE_DIR}/src/memory/prseg.c
  ${NSPR_SOURCE_DIR}/src/memory/prshm.c
  ${NSPR_SOURCE_DIR}/src/memory/prshma.c

  ${NSPR_SOURCE_DIR}/src/misc/pralarm.c
  ${NSPR_SOURCE_DIR}/src/misc/pratom.c
  ${NSPR_SOURCE_DIR}/src/misc/prcountr.c
  ${NSPR_SOURCE_DIR}/src/misc/prdtoa.c
  ${NSPR_SOURCE_DIR}/src/misc/prenv.c
  ${NSPR_SOURCE_DIR}/src/misc/prerr.c
  ${NSPR_SOURCE_DIR}/src/misc/prerror.c
  ${NSPR_SOURCE_DIR}/src/misc/prerrortable.c
  ${NSPR_SOURCE_DIR}/src/misc/prinit.c
  ${NSPR_SOURCE_DIR}/src/misc/prinrval.c
  ${NSPR_SOURCE_DIR}/src/misc/pripc.c
  ${NSPR_SOURCE_DIR}/src/misc/pripcsem.c
  ${NSPR_SOURCE_DIR}/src/misc/prlog2.c
  ${NSPR_SOURCE_DIR}/src/misc/prlong.c
  ${NSPR_SOURCE_DIR}/src/misc/prnetdb.c
  ${NSPR_SOURCE_DIR}/src/misc/praton.c
  ${NSPR_SOURCE_DIR}/src/misc/prolock.c
  ${NSPR_SOURCE_DIR}/src/misc/prrng.c
  ${NSPR_SOURCE_DIR}/src/misc/prsystem.c
  ${NSPR_SOURCE_DIR}/src/misc/prtime.c
  ${NSPR_SOURCE_DIR}/src/misc/prthinfo.c
  ${NSPR_SOURCE_DIR}/src/misc/prtpool.c
  ${NSPR_SOURCE_DIR}/src/misc/prtrace.c

  ${NSPR_SOURCE_DIR}/src/threads/combined/prucpu.c
  ${NSPR_SOURCE_DIR}/src/threads/combined/prucv.c
  ${NSPR_SOURCE_DIR}/src/threads/combined/prulock.c
  ${NSPR_SOURCE_DIR}/src/threads/combined/pruthr.c
  ${NSPR_SOURCE_DIR}/src/threads/combined/prustack.c

  ${NSPR_SOURCE_DIR}/src/threads/prcmon.c
  ${NSPR_SOURCE_DIR}/src/threads/prdump.c
  ${NSPR_SOURCE_DIR}/src/threads/prmon.c
  ${NSPR_SOURCE_DIR}/src/threads/prsem.c
  ${NSPR_SOURCE_DIR}/src/threads/prrwlock.c
  ${NSPR_SOURCE_DIR}/src/threads/prcthr.c
  ${NSPR_SOURCE_DIR}/src/threads/prtpd.c)

add_library(nspr ${LIBRARY_TYPE} ${NSPR_SRCS})
add_library(mozjs::nspr ALIAS nspr)

target_include_directories(nspr PUBLIC
  ${CMAKE_CURRENT_BINARY_DIR}
  ${NSPR_SOURCE_DIR}/include/md
  ${NSPR_SOURCE_DIR}/include/obsolete
  ${NSPR_SOURCE_DIR}/include/private
  ${NSPR_SOURCE_DIR}/include)

target_link_libraries(nspr PUBLIC advapi32 wsock32 winmm)

target_compile_definitions(nspr PRIVATE
  -D_NSPR_BUILD_
  -D_PR_GLOBAL_THREADS_ONLY
  -DXP_PC
  -DWIN95)

if(MOZJS_STATIC_LIB)
  target_compile_definitions(nspr PUBLIC -D_NSPR_STATIC_)
endif()

if(TARGET_CPU MATCHES "^x86_64$")
  target_compile_definitions(nspr PRIVATE
    -DUSE_64)
  message(STATUS "Build NSPR as 64-bit")
endif()

#target_compile_options(nspr PRIVATE /W0)

configure_file(${NSPR_SOURCE_DIR}/include/md/_win95.cfg ${CMAKE_CURRENT_BINARY_DIR}/prcpucfg.h COPYONLY)
target_sources(nspr PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/prcpucfg.h)

install(TARGETS nspr
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})

#####################################################################
## Testing
#####################################################################
enable_testing()

#####################################################################
## nspr (Tests)
## TODO: Add more tests
#####################################################################
add_executable(nspr_test_cleanup ${NSPR_SOURCE_DIR}/tests/cleanup.c)
target_link_libraries(nspr_test_cleanup PRIVATE mozjs::nspr mozjs::plc)
add_test(NAME nspr_test_cleanup COMMAND nspr_test_cleanup)
install(TARGETS nspr_test_cleanup DESTINATION ${CMAKE_INSTALL_PREFIX}/tests/nspr)

