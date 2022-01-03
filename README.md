# CppTemplate
This repo is a simple template to help you start a C/C++ project using CMake. The setup instructions are currently only for Windows but can be adapted for other platforms. The usage instructions should work on any platforms, apart from the method of executing the binary which will be different.

This system uses CMake and therefore the file type (.c or .cpp) dictates which compiler is used. If you want this to be a C project, ensure source files have the .c extension. For cpp the .cpp extension.

## Windows Setup (GCC)
### Compiler
I've found that the best way to get GCC on Windows is using MSYS2. If you have GCC installed or another compiler like MVSC or Clang, you can skip this step. 

This is a rewrite of [this guide on 
stackoverflow](https://stackoverflow.com/questions/30069830/how-to-install-mingw-w64-and-msys2).

- Download [MSYS2](https://www.msys2.org/) and install.     
- Run MSYS2.     
- Update package database and base package by running:
  - `packman -Syu`.     
- Relaunch MSYS2 and run to finish the process:
  - `packman -Su`    
- Install GCC by running (You may need to press enter when prompted what to install):
  - `pacman -S mingw-w64-x86_64-toolchain`
- or on 32 bit machines run:
  -  `pacman -S mingw-w64-i686-toolchain`.       
- Now start MSYS2 MinGW x64/x86 and check the install worked by running:
  -  `gcc --version`
- If this does provide output with a gcc version try repeating the above steps or create an issue in this repo. 

You now have your compiler install, to allow you access it anywhere without needing to provide its location add `<MSYS2 root>/mingw64/bin` or `<MSYS2 root>/mingw32/bin` (for 32 bit machines) to your PATH. This guide will assume that you have done this. 

### Build Tools and Version Control
Now we have our compiler working, we need the tools to build our programs. This can be done directly via the compiler with command line arguments however that gets boring fast. I do suggest you [look into how you compile programs](https://www.youtube.com/watch?v=VDslRumKvRA) just using the compiler as it will help your understanding but it's generally not recommended for everyday use. 

There are a couple of other programs required:
- [Git for Windows](https://gitforwindows.org/) - Our version control. 
- [CMake](https://cmake.org/download/) - CMake it self.

During this process, CMake will ask if you want it added to PATH, click yes as it will it make it a lot easier to run commands (and this guide will assume you have).    

Note: You need to download these for your Host OS, do not install them through MSYS2 as it will not work correctly.

## Usage
### Building and running the Project
First we need to get the project onto our local machine. This can be done two ways, either by downloading the repo from the Github website by using the `Code` button (or clicking this [link](https://github.com/ArchieAtkinson/CppTemplate/archive/refs/heads/main.zip)) or by using git.

To download repo with git we will clone the repo:
- Open Git Bash and navigate to where you would like the repo stored.
- Then clone it with the following command:  
  - `git clone https://github.com/ArchieAtkinson/CppTemplate.git`  

Once it has finished downloading (and you have unzipped if not using git) you are ready to start building and running the demo project.       

- The first step is to open a terminal and navigate inside the repo directory, any of the below terminals will work:
  - Command Prompt
  - Git Bash
  - Powershell
  - Bash
- Create a build directory with:
    - `mkdir build`    
- Configure CMake with Make as the generator:
    - `cmake -S . -B build -G "MinGW Makefiles"`
- To create a debug build just add the below flag to the end of the previous command:
  -  `-DCMAKE_BUILD_TYPE=Debug`  
- Now to build the project:
  - `cmake --build build`    
- If everything has gone to plan you can now run the binary with:
  -  `.\build\Debug\ProjectName.exe`
- And `Hello, World` and `RELEASE BUILD` (or `DEBUG BUILD`) should appear!    
 
You now have a basic C/C++ with CMake environment setup  

### Renaming the Project
The first step you may want to do is rename the project.
- Open the CMakeList.txt and change the line that reads `project(ProjectName)` to `project(YourProjectName)`.    
- In your terminal, in the project directory, run `cmake --build build --target clean` or delete the contents of the build folder.    
- This has removed the old stuff from the build folder and built your new project.    
- Now test the program by running `.\build\YourProjectName.exe` and you should get `Hello, World` back!

If you want to streamline your development cycle (and stopping having to type command as much) I suggest following my below guide on getting started wth Visual Studio Code (VSCode).

## VSCode Setup
VSCode is a great text editor that can be used as development environment on almost any platform and for any language. Below is a quick start guide to VSCode and CMake. I suggest you dig further into [VSCode](https://code.visualstudio.com/docs/introvideos/basics) and [CMake](https://www.youtube.com/watch?v=_yFPO1ofyF0&list=PLK6MXr8gasrGmIiSuVQXpfFuE1uPT615s) once you have everything setup as it will definitely help you out in the future. 

Note: Visual Studio Code (VSCode) is not the same as [Visual Studio](https://visualstudio.microsoft.com/). One is a code editor and the other is a fully packed IDE. 

- [Download VSCode](https://code.visualstudio.com/) if you haven't.
- Once downloaded, go the extensions tab of the left and install the following extensions:
    - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
    - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- Now open the directory of the project you setup earlier.
- If asked "Would you like to configure project 'CppTemplate'? Click `Yes` 
- You should now be able to see bar at bottom, shown below.   
![Annotated image of the cmake bar at the bottom left of VSCode](repo_assets/CMake_Bar.png)
    - The "Build Type" button lets you set your build for release or debug (or any other builds you want to support).
    - The "Kit" button lets you set your compiler, if you are following this guide on Windows you want to select the GCC...mingw32 option.
    - The "Build" button starts a build.
    - The "Debug" button starts a debugging session (It builds first, then launch the debugger).
    - The "Run" button starts the programing normally (It builds first, then launch).
    - These can all be bound to a key, see File->Preference->Keyboard Shortcuts.
- If you have already followed the setups in the [Building and running the Project](#building-and-running-the-project) section, you can just click the "Run" button and your program should launch.
- If this fails with the error `No useable generator found`, do the following:
  - File->Preference->Settings.
  - Search `generator`.
  - Add `MinGW Makefiles` to the `Cmake: Generator` field.
  - Now try clicking the build button. 

Note: Make sure your build is set to Debug while debugging or the debugger will not work.

## End Note
I plan to expand this project over time to cover more us cases and platforms. Feel free to create issues if you are having problem and I'll do my best to help, please be as descriptive as possible. Pull request are also welcome to improve the current template or add more.