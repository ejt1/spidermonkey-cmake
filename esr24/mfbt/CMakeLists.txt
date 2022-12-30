#####################################################################
## mfbt (Library)
#####################################################################
set(MFBT_SRCS
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/bignum.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/bignum-dtoa.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/cached-powers.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/diy-fp.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/double-conversion.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/fast-dtoa.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/fixed-dtoa.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/double-conversion/strtod.cc"

  "${CMAKE_CURRENT_SOURCE_DIR}/decimal/Decimal.cpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/HashFunctions.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Poison.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/SHA1.cpp")

add_library(mfbt ${LIBRARY_TYPE} ${MFBT_SRCS})
add_library(mozjs::mfbt ALIAS mfbt)

target_include_directories(mfbt
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/decimal
    ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/double-conversion
    ${CMAKE_CURRENT_BINARY_DIR}/include)

target_compile_definitions(mfbt PUBLIC -DIMPL_MFBT)

install(TARGETS mfbt
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})

set(MFBT_PUBLIC_HDRS
  ${CMAKE_CURRENT_SOURCE_DIR}/Assertions.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Atomics.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Attributes.h
  ${CMAKE_CURRENT_SOURCE_DIR}/BloomFilter.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Casting.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Char16.h
  ${CMAKE_CURRENT_SOURCE_DIR}/CheckedInt.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Compiler.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Constants.h
  ${CMAKE_CURRENT_SOURCE_DIR}/DebugOnly.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Endian.h
  ${CMAKE_CURRENT_SOURCE_DIR}/EnumSet.h
  ${CMAKE_CURRENT_SOURCE_DIR}/FloatingPoint.h
  ${CMAKE_CURRENT_SOURCE_DIR}/GuardObjects.h
  ${CMAKE_CURRENT_SOURCE_DIR}/HashFunctions.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Likely.h
  ${CMAKE_CURRENT_SOURCE_DIR}/LinkedList.h
  ${CMAKE_CURRENT_SOURCE_DIR}/MathAlgorithms.h
  ${CMAKE_CURRENT_SOURCE_DIR}/MemoryChecking.h
  ${CMAKE_CURRENT_SOURCE_DIR}/MSStdInt.h
  ${CMAKE_CURRENT_SOURCE_DIR}/NullPtr.h
  ${CMAKE_CURRENT_SOURCE_DIR}/PodOperations.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Poison.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Range.h
  ${CMAKE_CURRENT_SOURCE_DIR}/RangedPtr.h
  ${CMAKE_CURRENT_SOURCE_DIR}/RefPtr.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Scoped.h
  ${CMAKE_CURRENT_SOURCE_DIR}/SHA1.h
  ${CMAKE_CURRENT_SOURCE_DIR}/SplayTree.h
  ${CMAKE_CURRENT_SOURCE_DIR}/StandardInteger.h
  ${CMAKE_CURRENT_SOURCE_DIR}/ThreadLocal.h
  ${CMAKE_CURRENT_SOURCE_DIR}/TypedEnum.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Types.h
  ${CMAKE_CURRENT_SOURCE_DIR}/TypeTraits.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Util.h
  ${CMAKE_CURRENT_SOURCE_DIR}/WeakPtr.h)

foreach(_header ${MFBT_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${MOZJS_EXPORT_PREFIX}/mozilla/${_header_file} COPYONLY)
endforeach()

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/decimal/Decimal.h
  ${MOZJS_EXPORT_PREFIX}/mozilla/decimal/Decimal.h
  COPYONLY)

install(FILES ${MFBT_PUBLIC_HDRS}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/mozilla)
