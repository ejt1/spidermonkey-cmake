add_executable(shell js.cpp jsoptparse.cpp OSObject.cpp)

# Disable warnings because we're not gonna do anything about them anyway :)
target_compile_options(shell PRIVATE /W0)

target_link_libraries(shell PRIVATE mozjs::js mozjs::nspr mozjs::mfbt)

target_compile_definitions(shell PUBLIC -DIMPL_MFBT)

target_include_directories(shell PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(SELFHOSTING_SRCS
  "${CMAKE_CURRENT_SOURCE_DIR}/ModuleLoader.js")

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/shellmoduleloader.out.h
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND py ../src/builtin/embedjs.py -DDEBUG=1 -c "cl" -p "/P /Fi: " -m "${CMAKE_CURRENT_SOURCE_DIR}/../src/js.msg" -o ${CMAKE_CURRENT_BINARY_DIR}/shellmoduleloader.out.h -s ${CMAKE_CURRENT_BINARY_DIR}/shellmoduleloader.js -n "moduleloader" ${SELFHOSTING_SRCS}
  DEPENDS ${SELFHOSTING_SRCS} "${CMAKE_CURRENT_SOURCE_DIR}/../src/js.msg"
  COMMENT "Generating shellmoduleloader.out.h"
  VERBATIM)

set_source_files_properties(shellmoduleloader.out.h PROPERTIES GENERATED TRUE)
target_sources(shell PRIVATE shellmoduleloader.out.h)

install(TARGETS shell RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
