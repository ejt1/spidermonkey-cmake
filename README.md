# SpiderMonkey + CMake

Compiling SpiderMonkey for projects targeting MSVC is hard, this makes it a little easier.

Only supports compiling on Windows targeting MSVC, anything else is covered by the original source.



# Versions

- esr24
- esr31 not working!
- esr38

# Requirements

- Windows 10 (or 11? need testing)
- Visual Studio 2022 or later, earlier versions most likely will work but no promises :)
- CMake (included in Visual Studio)
- Ninja (optional, included in Visual Studio)

## Options

`MOZJS_ESR_VER` Select which ESR version to build\
`MOZJS_THREADSAFE` Makes SpiderMonkey use thread-safety features.\
`MOZJS_ENABLE_ION` This is currently forced enabled because of some compilation issues in debug builds\
`MOZJS_STATIC_LIB` Build as static library\
`MOZJS_STATIC_RTL` Link MSVC libraries statically instead of dynamically
