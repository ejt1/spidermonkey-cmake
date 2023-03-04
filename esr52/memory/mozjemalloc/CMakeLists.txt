set(MOZJEMALLOC_SRCS
  "${CMAKE_CURRENT_SOURCE_DIR}/jemalloc.c")

add_library(mozjemalloc ${MOZJEMALLOC_SRCS})
add_library(mozjs::mozjemalloc ALIAS mozjemalloc)

target_include_directories(mozjemalloc
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
  PUBLIC
    "${MOZJS_EXPORT_PREFIX}")

target_compile_definitions(mozjemalloc PRIVATE
  -DMOZ_JEMALLOC_IMPL
  -DMOZ_MEMORY_WINDOWS
  -DMOZ_MEMORY
  -DMALLOC_USABLE_SIZE_CONST_PTR=const)

install(TARGETS mozjemalloc
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})

set(MOZJEMALLOC_PUBLIC_HDRS
  "${CMAKE_CURRENT_SOURCE_DIR}/jemalloc_types.h")

foreach(_header ${MOZJEMALLOC_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${MOZJS_EXPORT_PREFIX}/${_header_file} COPYONLY)
endforeach()
