This isn't really abandoned as I am slowly working on it, but for the most part no new things will appear here any time soon.

# SourceEditor

SourceEditor is my attempt at making an editor suite, similar to Unreal or Unity, but for Source 1. Currently our tools are built using Source SDK as it allows us to use Source and it's various libraries. **Please keep in mind I don't fully know what I am doing, I work with C# mostly but in order to do this I have to work with C++ unless I want to spend time making C# stuff for the engine**

See our docs for information on how to build it, make your own tools and more.

## Why?
I got inspritation from the Source 2 tools and thought to myself "It'd be cool if something like that existed for Source 1" so I thought about this project and I started to do it.
I am in no way a professional programmer and my code is probably terrible, but it gets the job done and I can easily refactor it.

## Info
SourceEditor is licensed under the MIT license, you can find it's license [here](license_sourceeditor.md). As we are including Source SDK here, it is not licensed under MIT it is instead under it's own license, which you can find [here](license_sourceengine.md).

You can check out our trello [here](https://trello.com/b/jBHyA5mG/sourceeditor) this shows our current roadmap and things we plan to do.

## Building
This isn't really a tutorial on how to build the editor, you will need some basic idea on how to work with the Source SDK to build this project.

You'll need:
* Visual Studio 2013
* Qt 4.8.7 (This may be updated at some point)
* Mono (If you want the script system to work)
* Swig (To generated bindings for the script system)

Make sure Qt is inside the `src/thirdparty/qt` directory then run `create_sourceeditor.bat` and rebuild the entire solution. If you didn't add mono, then that project will fail to build but the editor should work fine without it due to the way the editor is coded.
