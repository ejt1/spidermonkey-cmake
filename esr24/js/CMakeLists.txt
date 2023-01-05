add_subdirectory(shell)

set(JS_GC_ZEAL ON)
set(MOZJS_ENABLE_ION ON)
set(JS_METHODJIT ON)
add_definitions(-DJS_ION)

#####################################################################
## SpiderMonkey (Library)
#####################################################################
# Listed in the same order as in js/src/moz.build
# Early version of js did not provide full path to source files
set(JS_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler/jit/ExecutableAllocator.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Eval.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Intl.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/MapObject.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Module.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Object.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/ParallelArray.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Profilers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/RegExp.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/TestingFunctions.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/devtools/sharkctl.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/ds/LifoAlloc.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/BytecodeCompiler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/BytecodeEmitter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/FoldConstants.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/NameFunctions.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/ParseMaps.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/ParseNode.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/Parser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/TokenStream.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Zone.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Verifier.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Statistics.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/StoreBuffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/RootMarking.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Nursery.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Marking.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Memory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Iteration.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/perf/jsperf.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ArgumentsObject.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/CharacterEncoding.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/DateTime.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Debugger.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ForkJoin.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/GlobalObject.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Interpreter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Monitor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ObjectImpl.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Probes.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/PropertyKey.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/RegExpObject.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/RegExpStatics.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/SPSProfiler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ScopeObject.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/SelfHosting.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Shape.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Stack.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/String.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/StringBuffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ThreadPool.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Unicode.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Xdr.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr/PageBlock.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr/YarrCanonicalizeUCS2.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr/YarrInterpreter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr/YarrPattern.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr/YarrSyntaxChecker.cpp
  
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsalloc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsanalyze.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsapi.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsarray.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsatom.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsbool.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsclone.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jscntxt.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jscompartment.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jscrashreport.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsdate.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsdbgapi.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsdtoa.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsexn.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsfriendapi.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsfun.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsgc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsinfer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsiter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsmath.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsmemorymetrics.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsnativestack.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsnum.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsobj.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/json.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsonparser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsopcode.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsprf.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jspropertytree.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsproxy.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsreflect.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsscript.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsstr.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jstypedarray.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsutil.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jswatchpoint.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsweakmap.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsworkers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jswrapper.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/prmjtime.cpp)

if(MOZ_INSTRUMENTS)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/devtools/Instrument.cpp)
endif()

if(ENABLE_TRACE_LOGGING)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TraceLogging.cpp)
endif()

if(MOZJS_ENABLE_ION)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/AliasAnalysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/AsmJS.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/AsmJSLink.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ASMJSSignalHandlers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BacktrackingAllocator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Bailouts.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineBailouts.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/BaselineCompiler-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineCompiler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineFrame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineFrameInfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineIC.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineInspector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineJIT.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BitSet.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BytecodeAnalysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/C1Spewer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/CodeGenerator-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/CodeGenerator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/EdgeCaseAnalysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/EffectiveAddressAnalysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Ion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonAnalysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonBuilder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonCaches.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonFrames.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonMacroAssembler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonSpewer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/JSONSpewer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/PerfSpewer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LICM.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LIR.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LinearScan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LiveRangeAllocator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/Lowering-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Lowering.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MCallOptimize.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MIR.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MIRGraph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MoveResolver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ParallelArrayAnalysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ParallelFunctions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/RangeAnalysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/RegisterAllocator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Safepoints.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Snapshots.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/StupidAllocator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/TypePolicy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/UnreachableCodeElimination.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/VMFunctions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ValueNumbering.cpp)

  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/Assembler-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/BaselineCompiler-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/BaselineIC-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/CodeGenerator-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/IonFrames-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/Lowering-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/MoveEmitter-x86-shared.cpp)

  if(TARGET_CPU MATCHES "x86_64")
    list(APPEND JS_SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/Assembler-x64.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/Bailouts-x64.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/BaselineCompiler-x64.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/BaselineIC-x64.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/CodeGenerator-x64.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/Lowering-x64.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/MacroAssembler-x64.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x64/Trampoline-x64.cpp)
  else()
    list(APPEND JS_SRCS
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/Assembler-x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/Bailouts-x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/BaselineCompiler-x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/BaselineIC-x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/CodeGenerator-x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/Lowering-x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/MacroAssembler-x86.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/x86/Trampoline-x86.cpp)
  endif()
endif()

# line 294, actually if-statement but we only compile on windows
list(APPEND JS_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler/jit/ExecutableAllocatorWin.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr/OSAllocatorWin.cpp)

if(MOZJS_ENABLE_ION OR MOZJS_ENABLE_YARR_JIT)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler/assembler/ARMAssembler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler/assembler/MacroAssemblerARM.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler/assembler/MacroAssemblerX86Common.cpp)
endif()

if(MOZJS_ENABLE_YARR_JIT)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr/YarrJIT.cpp)
endif()

list(APPEND JS_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/perf/pm_stub.cpp)
## End source files
###############################################################################
## Begin static library
add_library(js ${LIBRARY_TYPE} ${JS_SRCS})
add_library(mozjs::js ALIAS js)

# Disable warnings because we're not gonna do anything about them anyway :)
target_compile_options(js PRIVATE /W0)

set(JS_PUBLIC_HDRS
  ${CMAKE_CURRENT_SOURCE_DIR}/public/Anchor.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/CallArgs.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/CharacterEncoding.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/Date.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/GCAPI.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/HashTable.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/HeapAPI.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/LegacyIntTypes.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/MemoryMetrics.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/PropertyKey.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/RequiredDefines.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/RootingAPI.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/TemplateLib.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/Utility.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/Value.h
  ${CMAKE_CURRENT_SOURCE_DIR}/public/Vector.h)

foreach(_header ${JS_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${MOZJS_EXPORT_PREFIX}/js/${_header_file} COPYONLY)
endforeach()

set(JS_EXPORT_HDRS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/js.msg
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsalloc.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsapi.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsclass.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsclist.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jscpucfg.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsdbgapi.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsfriendapi.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jslock.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/perf/jsperf.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsprf.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsprototypes.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsproxy.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsprvtd.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jspubtd.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jstypes.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsutil.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsversion.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jswrapper.h)

foreach(_header ${JS_EXPORT_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${MOZJS_EXPORT_PREFIX}/${_header_file} COPYONLY)
endforeach()

add_dependencies(js host_jsoplengen)

target_include_directories(js
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler
    ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler/wtf
    ${CMAKE_CURRENT_SOURCE_DIR}/src/assembler/jit
    ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin
    ${CMAKE_CURRENT_SOURCE_DIR}/src/devtools
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ds
    ${CMAKE_CURRENT_SOURCE_DIR}/src/frontend
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/perf
    # DO NOT USE /vm HERE!!!
    #${CMAKE_CURRENT_SOURCE_DIR}/src/vm
    ${CMAKE_CURRENT_SOURCE_DIR}/src/yarr
  PUBLIC
    # Binary dir public because of shell.exe...
    ${CMAKE_CURRENT_BINARY_DIR}
    ${MOZJS_EXPORT_PREFIX})

target_link_libraries(js
  PRIVATE
    mozjs::intl
  PUBLIC
    mozjs::mfbt)

target_compile_definitions(js PUBLIC -DIMPL_MFBT)

if(MOZJS_THREADSAFE)
  target_link_libraries(js PUBLIC mozjs::nspr)
  target_compile_definitions(js PUBLIC JS_THREADSAFE)
endif()

if(MOZJS_ENABLE_ION)
  if(TARGET_CPU MATCHES "x86_64")
    target_compile_definitions(js PUBLIC JS_CPU_X64 JS_CODEGEN_X64 JS_PUNBOX64)
  else()
    target_compile_definitions(js PUBLIC JS_CPU_X86 JS_CODEGEN_X86 JS_NUNBOX32)
  endif()
endif()

if(MOZJS_STATIC_LIB)
  target_compile_definitions(js PUBLIC -DSTATIC_JS_API)
else()
  target_compile_definitions(js PRIVATE -DEXPORT_JS_API)
endif()

###############################################################################
## SpiderMonkey (Generate files)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/js-config.h.in ${MOZJS_EXPORT_PREFIX}/js-config.h)

add_executable(host_jskwgen ${CMAKE_CURRENT_SOURCE_DIR}/src/jskwgen.cpp)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/jsautokw.h
  COMMAND host_jskwgen jsautokw.h
  DEPENDS host_jskwgen
  COMMENT "Generating jsautokw.h"
  VERBATIM)

set_source_files_properties(jsautokw.h PROPERTIES GENERATED TRUE)
target_sources(js PRIVATE jsautokw.h)

add_executable(host_jsoplengen ${CMAKE_CURRENT_SOURCE_DIR}/src/jsoplengen.cpp)
add_dependencies(js host_jsoplengen)

add_custom_command(
  OUTPUT jsautooplen.h
  COMMAND host_jsoplengen jsautooplen.h
  DEPENDS host_jsoplengen
  COMMENT "Generating jsautooplen.h"
  VERBATIM)

set_source_files_properties(jsautooplen.h PROPERTIES GENERATED TRUE)
target_sources(js PRIVATE jsautooplen.h)

set(SELFHOSTING_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Utilities.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Array.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Date.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Intl.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/IntlData.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Number.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/ParallelArray.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/String.js)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.out.h
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  # HINT: /EP flag is required for MSVC C++ compiler to work
  # TODO: Automatically find python 2.7
  COMMAND C:/Python27/python.exe ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/embedjs.py -DDEBUG -p "${CMAKE_CXX_COMPILER} /EP" -m ${CMAKE_CURRENT_SOURCE_DIR}/src/js.msg -o ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.out.h -s ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.js ${SELFHOSTING_SRCS}
  DEPENDS ${SELFHOSTING_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/src/js.msg
  COMMENT "Generating selfhosted.out.h"
  VERBATIM)

set_source_files_properties(selfhosted.out.h PROPERTIES GENERATED TRUE)
target_sources(js PRIVATE selfhosted.out.h)

###############################################################################
## Begin install directives
install(TARGETS js
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})
