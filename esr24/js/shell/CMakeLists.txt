add_executable(shell js.cpp jsheaptools.cpp jsoptparse.cpp)

target_link_libraries(shell PRIVATE mozjs::js)

target_include_directories(shell PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../src)

install(TARGETS shell RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
