# TreeFunctions

## Setting Up

1. Open the Installer with Tools... -> Get Tools and Features...
2. Install the "Desktop development with C++" package, if you don't already have it
3. "C++ CMake tools for Windows are included" and "Test Adapter for Google Test" should be included

## Cloning the Repo

For a visual walkthrough, see https://www.youtube.com/watch?v=Sn3XiXd5zNQ

1. On the start screen, click "Clone a repository." (Or File - Clone Repository)
2. Paste this repo's URL: https://github.com/FongJoseph/TreeFunctions
3. Choose a local folder to clone to.
4. Visual Studio should detect CMake and configure the project automatically.
5. It may take some time if it needs to download the googletest libraries.

## Building and Running (Windows + Visual Studio)

1. Build -> Build All
2. To run the main program, run the "tree" target from Solution Explorer.
3. To run the unit tests, run the "test_tree" target from Solution Explorer, or use Test Explorer.
