add_library(example SHARED main.cpp)
target_link_libraries(example PRIVATE js)
install(TARGETS example
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
