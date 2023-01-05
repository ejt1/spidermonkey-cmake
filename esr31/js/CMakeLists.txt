#####################################################################
## SpiderMonkey (Library)
#####################################################################
set(JS_SOURCE_DIR ${MOZILLA_SOURCE}/js/src)
set(JS_SRCS
  ${JS_SOURCE_DIR}/assembler/jit/ExecutableAllocator.cpp

  ${JS_SOURCE_DIR}/builtin/Eval.cpp
  ${JS_SOURCE_DIR}/builtin/Intl.cpp
  ${JS_SOURCE_DIR}/builtin/MapObject.cpp
  ${JS_SOURCE_DIR}/builtin/Object.cpp
  ${JS_SOURCE_DIR}/builtin/Profilers.cpp
  ${JS_SOURCE_DIR}/builtin/RegExp.cpp
  ${JS_SOURCE_DIR}/builtin/SIMD.cpp
  ${JS_SOURCE_DIR}/builtin/TestingFunctions.cpp
  ${JS_SOURCE_DIR}/builtin/TypedObject.cpp
  
  ${JS_SOURCE_DIR}/devtools/sharkctl.cpp
  
  ${JS_SOURCE_DIR}/ds/LifoAlloc.cpp
  
  ${JS_SOURCE_DIR}/frontend/BytecodeCompiler.cpp
  ${JS_SOURCE_DIR}/frontend/BytecodeEmitter.cpp
  ${JS_SOURCE_DIR}/frontend/FoldConstants.cpp
  ${JS_SOURCE_DIR}/frontend/NameFunctions.cpp
  ${JS_SOURCE_DIR}/frontend/ParseMaps.cpp
  ${JS_SOURCE_DIR}/frontend/ParseNode.cpp
  ${JS_SOURCE_DIR}/frontend/Parser.cpp
  ${JS_SOURCE_DIR}/frontend/TokenStream.cpp
  
  ${JS_SOURCE_DIR}/gc/Barrier.cpp
  ${JS_SOURCE_DIR}/gc/Iteration.cpp
  ${JS_SOURCE_DIR}/gc/Marking.cpp
  ${JS_SOURCE_DIR}/gc/Memory.cpp
  ${JS_SOURCE_DIR}/gc/Nursery.cpp
  ${JS_SOURCE_DIR}/gc/RootMarking.cpp
  ${JS_SOURCE_DIR}/gc/Statistics.cpp
  ${JS_SOURCE_DIR}/gc/StoreBuffer.cpp
  ${JS_SOURCE_DIR}/gc/Tracer.cpp
  ${JS_SOURCE_DIR}/gc/Verifier.cpp
  ${JS_SOURCE_DIR}/gc/Zone.cpp
  
  ${JS_SOURCE_DIR}/vm/ArgumentsObject.cpp
  ${JS_SOURCE_DIR}/vm/ArrayBufferObject.cpp
  ${JS_SOURCE_DIR}/vm/CallNonGenericMethod.cpp
  ${JS_SOURCE_DIR}/vm/CharacterEncoding.cpp
  ${JS_SOURCE_DIR}/vm/Compression.cpp
  ${JS_SOURCE_DIR}/vm/DateTime.cpp
  ${JS_SOURCE_DIR}/vm/Debugger.cpp
  ${JS_SOURCE_DIR}/vm/DebuggerMemory.cpp
  ${JS_SOURCE_DIR}/vm/ErrorObject.cpp
  ${JS_SOURCE_DIR}/vm/ForkJoin.cpp
  ${JS_SOURCE_DIR}/vm/GlobalObject.cpp
  ${JS_SOURCE_DIR}/vm/Id.cpp
  ${JS_SOURCE_DIR}/vm/Interpreter.cpp
  ${JS_SOURCE_DIR}/vm/MemoryMetrics.cpp
  ${JS_SOURCE_DIR}/vm/Monitor.cpp
  ${JS_SOURCE_DIR}/vm/ObjectImpl.cpp
  ${JS_SOURCE_DIR}/vm/OldDebugAPI.cpp
  ${JS_SOURCE_DIR}/vm/PIC.cpp
  ${JS_SOURCE_DIR}/vm/Probes.cpp
  ${JS_SOURCE_DIR}/vm/PropertyKey.cpp
  ${JS_SOURCE_DIR}/vm/ProxyObject.cpp
  ${JS_SOURCE_DIR}/vm/RegExpObject.cpp
  ${JS_SOURCE_DIR}/vm/RegExpStatics.cpp
  ${JS_SOURCE_DIR}/vm/Runtime.cpp
  ${JS_SOURCE_DIR}/vm/SavedStacks.cpp
  ${JS_SOURCE_DIR}/vm/ScopeObject.cpp
  ${JS_SOURCE_DIR}/vm/SelfHosting.cpp
  ${JS_SOURCE_DIR}/vm/Shape.cpp
  ${JS_SOURCE_DIR}/vm/SharedArrayObject.cpp
  ${JS_SOURCE_DIR}/vm/SPSProfiler.cpp
  ${JS_SOURCE_DIR}/vm/Stack.cpp
  ${JS_SOURCE_DIR}/vm/String.cpp
  ${JS_SOURCE_DIR}/vm/StringBuffer.cpp
  ${JS_SOURCE_DIR}/vm/StructuredClone.cpp
  ${JS_SOURCE_DIR}/vm/ThreadPool.cpp
  ${JS_SOURCE_DIR}/vm/TypedArrayObject.cpp
  ${JS_SOURCE_DIR}/vm/Unicode.cpp
  ${JS_SOURCE_DIR}/vm/Value.cpp
  ${JS_SOURCE_DIR}/vm/WeakMapPtr.cpp
  ${JS_SOURCE_DIR}/vm/Xdr.cpp

  ${JS_SOURCE_DIR}/yarr/PageBlock.cpp
  ${JS_SOURCE_DIR}/yarr/YarrCanonicalizeUCS2.cpp
  ${JS_SOURCE_DIR}/yarr/YarrInterpreter.cpp
  ${JS_SOURCE_DIR}/yarr/YarrPattern.cpp
  ${JS_SOURCE_DIR}/yarr/YarrSyntaxChecker.cpp

  ${JS_SOURCE_DIR}/perf/jsperf.cpp
  
  ${JS_SOURCE_DIR}/jsalloc.cpp
  ${JS_SOURCE_DIR}/jsanalyze.cpp
  ${JS_SOURCE_DIR}/jsapi.cpp
  ${JS_SOURCE_DIR}/jsarray.cpp
  ${JS_SOURCE_DIR}/jsatom.cpp
  ${JS_SOURCE_DIR}/jsbool.cpp
  ${JS_SOURCE_DIR}/jscntxt.cpp
  ${JS_SOURCE_DIR}/jscompartment.cpp
  ${JS_SOURCE_DIR}/jscrashreport.cpp
  ${JS_SOURCE_DIR}/jsdate.cpp
  ${JS_SOURCE_DIR}/jsdtoa.cpp
  ${JS_SOURCE_DIR}/jsexn.cpp
  ${JS_SOURCE_DIR}/jsfriendapi.cpp
  ${JS_SOURCE_DIR}/jsfun.cpp
  ${JS_SOURCE_DIR}/jsgc.cpp
  ${JS_SOURCE_DIR}/jsinfer.cpp
  ${JS_SOURCE_DIR}/jsiter.cpp
  ${JS_SOURCE_DIR}/jsmath.cpp
  ${JS_SOURCE_DIR}/jsnativestack.cpp
  ${JS_SOURCE_DIR}/jsnum.cpp
  ${JS_SOURCE_DIR}/jsobj.cpp
  ${JS_SOURCE_DIR}/json.cpp
  ${JS_SOURCE_DIR}/jsonparser.cpp
  ${JS_SOURCE_DIR}/jsopcode.cpp
  ${JS_SOURCE_DIR}/jsprf.cpp
  ${JS_SOURCE_DIR}/jspropertytree.cpp
  ${JS_SOURCE_DIR}/jsproxy.cpp
  ${JS_SOURCE_DIR}/jsreflect.cpp
  ${JS_SOURCE_DIR}/jsscript.cpp
  ${JS_SOURCE_DIR}/jsstr.cpp
  ${JS_SOURCE_DIR}/jsutil.cpp
  ${JS_SOURCE_DIR}/jswatchpoint.cpp
  ${JS_SOURCE_DIR}/jsweakmap.cpp
  ${JS_SOURCE_DIR}/jsworkers.cpp
  ${JS_SOURCE_DIR}/jswrapper.cpp
  ${JS_SOURCE_DIR}/prmjtime.cpp)

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
    ${JS_SOURCE_DIR}/jit/shared/BaselineCompiler-shared.cpp
    ${JS_SOURCE_DIR}/jit/shared/CodeGenerator-shared.cpp
    ${JS_SOURCE_DIR}/jit/shared/Lowering-shared.cpp

    ${JS_SOURCE_DIR}/jit/AliasAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/AsmJS.cpp
    ${JS_SOURCE_DIR}/jit/AsmJSLink.cpp
    ${JS_SOURCE_DIR}/jit/AsmJSModule.cpp
    ${JS_SOURCE_DIR}/jit/ASMJSSignalHandlers.cpp
    ${JS_SOURCE_DIR}/jit/BacktrackingAllocator.cpp
    ${JS_SOURCE_DIR}/jit/Bailouts.cpp
    ${JS_SOURCE_DIR}/jit/BaselineBailouts.cpp
    ${JS_SOURCE_DIR}/jit/BaselineCompiler.cpp
    ${JS_SOURCE_DIR}/jit/BaselineDebugModeOSR.cpp
    ${JS_SOURCE_DIR}/jit/BaselineFrame.cpp
    ${JS_SOURCE_DIR}/jit/BaselineFrameInfo.cpp
    ${JS_SOURCE_DIR}/jit/BaselineIC.cpp
    ${JS_SOURCE_DIR}/jit/BaselineInspector.cpp
    ${JS_SOURCE_DIR}/jit/BaselineJIT.cpp
    ${JS_SOURCE_DIR}/jit/BitSet.cpp
    ${JS_SOURCE_DIR}/jit/BytecodeAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/C1Spewer.cpp
    ${JS_SOURCE_DIR}/jit/CodeGenerator.cpp
    ${JS_SOURCE_DIR}/jit/CompileWrappers.cpp
    ${JS_SOURCE_DIR}/jit/EdgeCaseAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/EffectiveAddressAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/Ion.cpp
    ${JS_SOURCE_DIR}/jit/IonAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/IonBuilder.cpp
    ${JS_SOURCE_DIR}/jit/IonCaches.cpp
    ${JS_SOURCE_DIR}/jit/IonFrames.cpp
    ${JS_SOURCE_DIR}/jit/IonMacroAssembler.cpp
    ${JS_SOURCE_DIR}/jit/IonOptimizationLevels.cpp
    ${JS_SOURCE_DIR}/jit/IonSpewer.cpp
    ${JS_SOURCE_DIR}/jit/JitOptions.cpp
    ${JS_SOURCE_DIR}/jit/JSONSpewer.cpp
    ${JS_SOURCE_DIR}/jit/LICM.cpp
    ${JS_SOURCE_DIR}/jit/LinearScan.cpp
    ${JS_SOURCE_DIR}/jit/LIR.cpp
    ${JS_SOURCE_DIR}/jit/LiveRangeAllocator.cpp
    ${JS_SOURCE_DIR}/jit/Lowering.cpp
    ${JS_SOURCE_DIR}/jit/MCallOptimize.cpp
    ${JS_SOURCE_DIR}/jit/MIR.cpp
    ${JS_SOURCE_DIR}/jit/MIRGraph.cpp
    ${JS_SOURCE_DIR}/jit/MoveResolver.cpp
    ${JS_SOURCE_DIR}/jit/ParallelFunctions.cpp
    ${JS_SOURCE_DIR}/jit/ParallelSafetyAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/PerfSpewer.cpp
    ${JS_SOURCE_DIR}/jit/RangeAnalysis.cpp
    ${JS_SOURCE_DIR}/jit/Recover.cpp
    ${JS_SOURCE_DIR}/jit/RegisterAllocator.cpp
    ${JS_SOURCE_DIR}/jit/RematerializedFrame.cpp
    ${JS_SOURCE_DIR}/jit/Safepoints.cpp
    ${JS_SOURCE_DIR}/jit/Snapshots.cpp
    ${JS_SOURCE_DIR}/jit/StupidAllocator.cpp
    ${JS_SOURCE_DIR}/jit/TypeDescrSet.cpp
    ${JS_SOURCE_DIR}/jit/TypePolicy.cpp
    ${JS_SOURCE_DIR}/jit/UnreachableCodeElimination.cpp
    ${JS_SOURCE_DIR}/jit/ValueNumbering.cpp
    ${JS_SOURCE_DIR}/jit/VMFunctions.cpp)

  if(TARGET_CPU MATCHES "^x86.+$")
    message(STATUS "Build windows ION")
    list(APPEND JS_SRCS
      ${JS_SOURCE_DIR}/jit/shared/Assembler-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/BaselineCompiler-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/BaselineIC-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/CodeGenerator-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/Lowering-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/MacroAssembler-x86-shared.cpp
      ${JS_SOURCE_DIR}/jit/shared/MoveEmitter-x86-shared.cpp)

    if(TARGET_CPU MATCHES "^x86_64$")
      message(STATUS "Build x64 ION")
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
    message(STATUS "Build x86 ION")
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

if(MOZJS_ENABLE_VTUNE)
  list(APPEND JS_SRCS
    ${JS_SOURCE_DIR}/vtune/jitprofiling.cpp)
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
  ${JS_SOURCE_DIR}/../public/CallNonGenericMethod.h
  ${JS_SOURCE_DIR}/../public/CharacterEncoding.h
  ${JS_SOURCE_DIR}/../public/Class.h
  ${JS_SOURCE_DIR}/../public/Date.h
  ${JS_SOURCE_DIR}/../public/GCAPI.h
  ${JS_SOURCE_DIR}/../public/HashTable.h
  ${JS_SOURCE_DIR}/../public/HeapAPI.h
  ${JS_SOURCE_DIR}/../public/Id.h
  ${JS_SOURCE_DIR}/../public/LegacyIntTypes.h
  ${JS_SOURCE_DIR}/../public/MemoryMetrics.h
  ${JS_SOURCE_DIR}/../public/OldDebugAPI.h
  ${JS_SOURCE_DIR}/../public/Principals.h
  ${JS_SOURCE_DIR}/../public/ProfilingStack.h
  ${JS_SOURCE_DIR}/../public/PropertyKey.h
  ${JS_SOURCE_DIR}/../public/RequiredDefines.h
  ${JS_SOURCE_DIR}/../public/RootingAPI.h
  ${JS_SOURCE_DIR}/../public/SliceBudget.h
  ${JS_SOURCE_DIR}/../public/StructuredClone.h
  ${JS_SOURCE_DIR}/../public/TracingAPI.h
  ${JS_SOURCE_DIR}/../public/TypeDecls.h
  ${JS_SOURCE_DIR}/../public/Utility.h
  ${JS_SOURCE_DIR}/../public/Value.h
  ${JS_SOURCE_DIR}/../public/Vector.h
  ${JS_SOURCE_DIR}/../public/WeakMapPtr.h)

foreach(_header ${JS_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${CMAKE_CURRENT_BINARY_DIR}/include/js/${_header_file} COPYONLY)
endforeach()

set(JS_EXPORT_HDRS
  ${JS_SOURCE_DIR}/js.msg
  ${JS_SOURCE_DIR}/jsalloc.h
  ${JS_SOURCE_DIR}/jsapi.h
  ${JS_SOURCE_DIR}/jsbytecode.h
  ${JS_SOURCE_DIR}/jsclist.h
  ${JS_SOURCE_DIR}/jscpucfg.h
  ${JS_SOURCE_DIR}/jsfriendapi.h
  ${JS_SOURCE_DIR}/perf/jsperf.h
  ${JS_SOURCE_DIR}/jsprf.h
  ${JS_SOURCE_DIR}/jsprototypes.h
  ${JS_SOURCE_DIR}/jsproxy.h
  ${JS_SOURCE_DIR}/jspubtd.h
  ${JS_SOURCE_DIR}/jstypes.h
  ${JS_SOURCE_DIR}/jsversion.h
  ${JS_SOURCE_DIR}/jswrapper.h)

foreach(_header ${JS_EXPORT_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${CMAKE_CURRENT_BINARY_DIR}/include/${_header_file} COPYONLY)
endforeach()

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

target_compile_definitions(js
  PRIVATE
    -DHAVE_LOG2
    -DHAVE_LOG1P
    -DHAVE_EXPM1
    -DHAVE_ACOSH
    -DHAVE_ATANH
    -DHAVE_TRUNC
    -DHAVE_CBRT
    -D_CRT_RAND_S
  PUBLIC
    -DIMPL_MFBT)

if(MOZJS_ENABLE_ION)
  target_compile_definitions(js PUBLIC -DJS_ION)
  if (TARGET_CPU MATCHES "^x86_64$")
    target_compile_definitions(js PUBLIC -DJS_CODEGEN_X64 -DJS_PUNBOX64 -DJS_CPU_X64)
  else()
    target_compile_definitions(js PUBLIC -DJS_CODEGEN_X86 -DJS_NUNBOX32 -DJS_CPU_X86)
  endif()
endif()

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

set(SELFHOSTING_SRCS
  ${JS_SOURCE_DIR}/builtin/Utilities.js
  ${JS_SOURCE_DIR}/builtin/ParallelUtilities.js
  ${JS_SOURCE_DIR}/builtin/Array.js
  ${JS_SOURCE_DIR}/builtin/Date.js
  ${JS_SOURCE_DIR}/builtin/Intl.js
  ${JS_SOURCE_DIR}/builtin/IntlData.js
  ${JS_SOURCE_DIR}/builtin/Iterator.js
  ${JS_SOURCE_DIR}/builtin/Map.js
  ${JS_SOURCE_DIR}/builtin/Number.js
  ${JS_SOURCE_DIR}/builtin/String.js
  ${JS_SOURCE_DIR}/builtin/Set.js
  ${JS_SOURCE_DIR}/builtin/TypedObject.js)

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
