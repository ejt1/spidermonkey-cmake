#####################################################################
## Options
option(MOZJS_THREADSAFE "Build SpiderMonkey with thread-safety" ON)
option(MOZJS_ENABLE_ION "Build SpiderMonkey with method-jit" ON)
option(MOZJS_STATIC_LIB "Build SpiderMonkey as a static library" OFF)
option(MOZJS_STATIC_RTL "Link msvc runtime libraries statically" OFF)
option(MOZJS_ESR_VER "Mozilla ESR version" "esr45")
