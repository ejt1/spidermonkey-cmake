# SpiderMonkey + CMake

Compiling SpiderMonkey for projects using MSVC is hard, this makes it a little easier.

# Requirements

- Windows 10 (or 11? need testing)
- Visual Studio 2022 or later, earlier versions most likely will work but no promises :)
- CMake (included in Visual Studio)
- Ninja (optional, included in Visual Studio)

# How to compile

First you will need a local copy of the Mozilla source code, the recommended way is using Mercurial described
[here](https://firefox-source-docs.mozilla.org/setup/windows_build.html#building-firefox-on-windows), better grab a cup
of coffee because this is going to take a while.

Once you have an up-to-date copy of the source code you need to decide which ESR you want to build, look at <LINK HERE>
what ESR versions are currently supported.

Once you figure out which of the supported ESR you want to build you need to checkout that version. Using MozillaBuild
go into your mozilla source directory and run the command `hg bookmarks`, this will display all the available bookmarks
(similar to tags/branches for us humans that use git), once you locate the ESR you want run `hg up esr` replacing `[esr]`
with the version eg. `hg up esr24`.

Phew, almost done!

I already know you're reading this while that Mercurial download is going on so while you're waiting for that (or done if you
stopped reading and just looked at that download time going down) you can start configuring this project so it's ready
once the download is done burning a hole in your harddrive.

There is only really one step to configure this project and that is going into `CMakePresets.json` and changing the
`MOZILLA_SOURCE` to the location of your (soon) to be mozilla source directory.

If you want (and why wouldn't you), you can look at the options located near the top of `CMakeLists.txt`. Those options
can be set just like you did the source directory.

## Options

`MOZILLA_SOURCE` Location of the Mozilla source directory\
`MOZJS_THREADSAFE` Makes SpiderMonkey use thread-safety features.\
`MOZJS_ENABLE_ION` Enable [ION?](https://wiki.mozilla.org/IonMonkey)\
`MOZJS_STATIC_LIB` Build as static library\
`MOZJS_STATIC_RTL` (NOT WORKING) Link MSVC libraries statically instead of dynamically

## Link with your project

How you want to link SpiderMonkey with your project depends on what build system you are using. Recommended is using
CMake which makes linking very simple, look under `example` for how to do this.

If more examples on how to link with your preferred build system is needed please open an issue or even better open a pull request :)

# What's up with nsprpub?

NSPR is the one codebase we HAVE TO modify, the copy distributed in mozilla-central will not properly compile as a
static library. Until I have time to create and apply patches for NSPR the quick way is just keep a local
modified copy of the source.

# Planned features (probably never gonna happen, PRs welcomed)

- Add option to copy the sources from mozilla-central as part of the build steps which can be uploaded as self-contained
sources removing the need to pull the entire mozilla-central
- More ESR versions (this probably will happen)
- Make patches for NSPR
- Implement the option for static RTL (this will also probably happen)
- Proof-read this readme because per usual been at it for to long
