cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(mozjs)

include("cmake/options.cmake")
include("cmake/configure.cmake")

#####################################################################
## Choosing version
## TODO: Support more ESR versions, goal is all available as boomarks
## in the Mercurial repository
add_subdirectory(${MOZJS_ESR_VER})

