# BUG: JSGC_INCREMENTAL must be defined because it is used without checking if defined in jsgc.cpp#4651
set(JSGC_INCREMENTAL ON)

if(CMAKE_BUILD_TYPE MATCHES "^(D|d)ebug$")
  set(JS_DEBUG ON)

  # BUG: ION is required for debug builds (for some fucking reason!)
  set(MOZJS_ENABLE_ION ON)
endif()

add_subdirectory(intl)
#add_subdirectory(js)
add_subdirectory(mfbt)
add_subdirectory(nsprpub)
