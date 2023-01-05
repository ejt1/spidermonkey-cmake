# BUG: JSGC_INCREMENTAL must be defined because it is used without checking if defined in jsgc.cpp#4511
add_definitions(-DJSGC_INCREMENTAL)

add_subdirectory(intl)
add_subdirectory(js)
add_subdirectory(memory)
add_subdirectory(mfbt)
add_subdirectory(modules)
add_subdirectory(nsprpub)
