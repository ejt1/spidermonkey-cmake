#####################################################################
## mozglue (Library)
#####################################################################
set(MOZGLUE_SRCS
  "${CMAKE_CURRENT_SOURCE_DIR}/misc/StackWalk.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/misc/TimeStamp.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/misc/TimeStamp_windows.cpp")

add_library(mozglue ${LIBRARY_TYPE} ${MOZGLUE_SRCS})
add_library(mozjs::mozglue ALIAS mozglue)

target_include_directories(mozglue
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
  PUBLIC
    "${MOZJS_EXPORT_PREFIX}")

target_compile_definitions(mozglue PUBLIC -DIMPL_MFBT -DMOZ_HAS_MOZGLUE)

install(TARGETS mozglue
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${LIBRARY_DIR})

set(MOZGLUE_PUBLIC_HDRS
  "${CMAKE_CURRENT_SOURCE_DIR}/misc/StackWalk.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/misc/StackWalk_windows.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/misc/TimeStamp.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/misc/TimeStamp_windows.h")

foreach(_header ${MOZGLUE_PUBLIC_HDRS})
  get_filename_component(_header_file ${_header} NAME)
  configure_file(${_header} ${MOZJS_EXPORT_PREFIX}/mozilla/${_header_file} COPYONLY)
endforeach()

install(FILES ${MFBT_PUBLIC_HDRS}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/mozilla)
