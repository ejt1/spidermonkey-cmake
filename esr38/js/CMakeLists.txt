add_subdirectory(shell)

set(JS_GC_ZEAL ON)

#####################################################################
## SpiderMonkey (Library)
#####################################################################
# Listed in the same order as in js/src/moz.build
# Early version of js did not provide full path to source files
set(JS_SRCS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/asmjs/AsmJSFrameIterator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/asmjs/AsmJSLink.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/asmjs/AsmJSModule.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/asmjs/AsmJSSignalHandlers.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/asmjs/AsmJSValidate.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/AtomicsObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Eval.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Intl.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/MapObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Object.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Profilers.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/SIMD.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/SymbolObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/RegExp.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/TestingFunctions.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/TypedObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/WeakSetObject.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/devtools/sharkctl.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/ds/LifoAlloc.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/BytecodeCompiler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/BytecodeEmitter.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/FoldConstants.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/NameFunctions.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/ParseMaps.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/ParseNode.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/Parser.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/TokenStream.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Barrier.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/GCTrace.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Iteration.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Marking.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Memory.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Nursery.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/RootMarking.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Statistics.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/StoreBuffer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Tracer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Verifier.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/gc/Zone.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/irregexp/NativeRegExpMacroAssembler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/irregexp/RegExpAST.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/irregexp/RegExpEngine.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/irregexp/RegExpInterpreter.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/irregexp/RegExpMacroAssembler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/irregexp/RegExpParser.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/irregexp/RegExpStack.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/AliasAnalysis.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BacktrackingAllocator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Bailouts.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineBailouts.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineCompiler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineDebugModeOSR.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineFrame.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineFrameInfo.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineIC.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineInspector.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BaselineJIT.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BitSet.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/BytecodeAnalysis.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/C1Spewer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/CodeGenerator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/CompileWrappers.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Disassembler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/EdgeCaseAnalysis.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/EffectiveAddressAnalysis.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ExecutableAllocator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Ion.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonAnalysis.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonBuilder.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonCaches.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/IonOptimizationLevels.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/JitcodeMap.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/JitFrames.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/JitOptions.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/JitSpewer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/JSONSpewer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LICM.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LinearScan.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LIR.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LiveRangeAllocator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/LoopUnroller.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Lowering.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MacroAssembler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MCallOptimize.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MIR.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MIRGraph.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/MoveResolver.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/OptimizationTracking.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/PerfSpewer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/RangeAnalysis.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Recover.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/RegisterAllocator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/RematerializedFrame.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Safepoints.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ScalarReplacement.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/BaselineCompiler-shared.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/CodeGenerator-shared.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/Lowering-shared.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Sink.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/Snapshots.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/StupidAllocator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/TypedObjectPrediction.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/TypePolicy.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ValueNumbering.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jit/VMFunctions.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsalloc.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsapi.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsbool.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jscntxt.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jscompartment.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsdate.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsdtoa.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsexn.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsfriendapi.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsfun.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsgc.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsiter.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsnativestack.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsnum.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsobj.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/json.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsopcode.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsprf.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jspropertytree.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsreflect.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsscript.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsstr.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jswatchpoint.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsweakmap.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/prmjtime.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsarray.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsatom.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsmath.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/jsutil.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/perf/jsperf.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/BaseProxyHandler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/CrossCompartmentWrapper.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/DeadObjectProxy.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/DirectProxyHandler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/Proxy.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/ScriptedDirectProxyHandler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/ScriptedIndirectProxyHandler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/SecurityWrapper.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/proxy/Wrapper.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ArgumentsObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ArrayBufferObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/CallNonGenericMethod.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/CharacterEncoding.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Compression.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/DateTime.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Debugger.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/DebuggerMemory.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ErrorObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ForOfIterator.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/GeneratorObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/GlobalObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/HelperThreads.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Id.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Interpreter.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/JSONParser.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/MemoryMetrics.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Monitor.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/NativeObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ObjectGroup.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/PIC.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Probes.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ProxyObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/RegExpObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/RegExpStatics.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Runtime.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/SavedStacks.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/ScopeObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/SelfHosting.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Shape.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/SharedArrayObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/SharedTypedArrayObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/SPSProfiler.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Stack.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/String.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/StringBuffer.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/StructuredClone.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Symbol.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/TypedArrayObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/TypeInference.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/UbiNode.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/UnboxedObject.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Unicode.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Value.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/WeakMapPtr.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/vm/Xdr.cpp")

if(MOZ_INSTRUMENTS)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/devtools/Instrument.cpp)
endif()

if(ENABLE_TRACE_LOGGING)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TraceLogging.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TraceLoggingGraph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TraceLoggingTypes.cpp)
endif()

if(MOZJS_ENABLE_ION)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/Assembler-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/AssemblerBuffer-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/BaselineCompiler-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/BaselineIC-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/CodeGenerator-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/Disassembler-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/Lowering-x86-shared.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/shared/MacroAssembler-x86-shared.cpp
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
else()
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/none/Trampoline-none.cpp)
endif()

# Can be moved up because we only compile windows so will always use these
list(APPEND JS_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jit/ExecutableAllocatorWin.cpp)

if(MOZJS_HAS_CTYPES)
  list(APPEND JS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ctypes/CTypes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ctypes/Library.cpp)
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
  "${CMAKE_CURRENT_SOURCE_DIR}/public/CallArgs.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/CallNonGenericMethod.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/CharacterEncoding.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Class.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Conversions.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Date.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Debug.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/GCAPI.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/HashTable.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/HeapAPI.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Id.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/LegacyIntTypes.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/MemoryMetrics.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Principals.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/ProfilingFrameIterator.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/ProfilingStack.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Proxy.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/RequiredDefines.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/RootingAPI.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/SliceBudget.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/StructuredClone.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/TracingAPI.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/TrackedOptimizationInfo.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/TypeDecls.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/UbiNode.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/UbiNodeTraverse.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Utility.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Value.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/Vector.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/public/WeakMapPtr.h")

foreach(_header ${JS_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${MOZJS_EXPORT_PREFIX}/js/${_header_file} COPYONLY)
endforeach()

set(JS_EXPORT_HDRS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/perf/jsperf.h

  ${CMAKE_CURRENT_SOURCE_DIR}/src/js.msg
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsalloc.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsapi.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsbytecode.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsclist.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jscpucfg.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsfriendapi.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsprf.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsprototypes.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jspubtd.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jstypes.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jsversion.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jswrapper.h)

foreach(_header ${JS_EXPORT_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${MOZJS_EXPORT_PREFIX}/${_header_file} COPYONLY)
endforeach()

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

target_link_libraries(js PRIVATE mozjs::intl PUBLIC mozjs::mfbt mozjs::zlib)

target_compile_definitions(js PUBLIC -DIMPL_MFBT)

if(MOZJS_THREADSAFE)
  target_link_libraries(js PUBLIC mozjs::nspr)
  target_compile_definitions(js PUBLIC JS_THREADSAFE)
endif()

target_compile_definitions(js PUBLIC
  -DIMPL_MFBT
  -DMOZ_CHAR16_IS_NOT_WCHAR
  -D_CRT_RAND_S
  -DHAVE_LOG2)

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

set(SELFHOSTING_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Utilities.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Array.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Date.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Error.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Generator.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Intl.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/IntlData.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Iterator.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Map.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Number.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Object.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/String.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/Set.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/TypedArray.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/TypedObject.js
  ${CMAKE_CURRENT_SOURCE_DIR}/src/builtin/WeakSet.js)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.out.h
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND py src/builtin/embedjs.py -DDEBUG=1 -c "cl" -p "/P /Fi: " -m src/js.msg -o ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.out.h -s ${CMAKE_CURRENT_BINARY_DIR}/selfhosted.js ${SELFHOSTING_SRCS}
  DEPENDS ${SELFHOSTING_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/src/js.msg
  COMMENT "Generating selfhosted.out.h"
  VERBATIM)

set_source_files_properties(selfhosted.out.h PROPERTIES GENERATED TRUE)
target_sources(js PRIVATE selfhosted.out.h)

###############################################################################
## Begin install directives
install(TARGETS js
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})
install(DIRECTORY "${MOZJS_EXPORT_PREFIX}"
  DESTINATION ${CMAKE_INSTALL_PREFIX})
