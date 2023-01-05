add_executable(shell js.cpp jsheaptools.cpp jsoptparse.cpp OSObject.cpp)

target_link_libraries(shell PRIVATE mozjs::js mozjs::nspr mozjs::mfbt)

target_compile_definitions(shell PUBLIC -DIMPL_MFBT)

target_include_directories(shell PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../src)

install(TARGETS shell RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
