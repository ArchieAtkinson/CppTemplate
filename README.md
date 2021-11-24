# CppTemplate

This repo is a simple template to start Cpp Projects using CMake. The setup instructions are currently only for Windows but can be adapter for other platforms. The usage instructions should work on any platforms, apart from the method of excuting the binary which will be 
different on other platforms. 

I plan to expand this project as I develop a better understanding on CMake. Feel free to create issues if you are having problem and I'll do my best to help, please be as descriptive as possible. Pull request are also welcome to improve the current template or add more. 

## Setup

Skip this step if you have your compiler and build tools setup

### Windows (GCC)

**Compiler:**

Based off [this guide on 
stackoverflow](https://stackoverflow.com/questions/30069830/how-to-install-mingw-w64-and-msys2)

- Download [MSYS2](https://www.msys2.org/) and install     
- Run MSYS2     
- Update package database and base package by running `packman -Syu`     
- Relaunch MSYS2 and run `packman -Su` to finish the process      
- Install GCC by running `pacman -S mingw-w64-x86_64-toolchain` (or on 32 bit machines run `pacman -S mingw-w64-i686-toolchain`)       
- Restart MSYS2 and check the install worked by running `gcc --version`, if this does provide output with a gcc version try repeating the above steps or create an issue in this repo     

You now have your compiler install, to allow you access it anywhere without needing to provide its location add `<MSYS2 root>/mingw64/bin` or `<MSYS2 root>/mingw32/bin` to your PATH. 

**Build Tools:**

There are a couple of other programs required:
- [Git for Windows](https://gitforwindows.org/)   
- [CMake](https://cmake.org/download/) 
- (Optional) [Ninja](https://github.com/ninja-build/ninja/releases) (I suggest creating a `ninja` folder in you C drive and moving the ninja.exe to it)     

During this process, if offered, add the binary to PATH. If not offered do it you self. This make life a lot easier as then you don't need to deal with filepaths. This guide will assume all the tools we are using at in the PATH.    


## Usage

### Builing and running the Project

- Clone the repo and enter the directory in your terminal    
- Create a build directory with `mkdir build`    
- Configure CMake with `cmake -S . -B build` or to use Ninja `cmake -S . -B build -G Ninja`  
- Now to build the project `cmake --build build`    
- If anything has gone to plan you can now run the binary with `.\build\Debug\ProjectName.exe` or `build\ProjectName.exe` (depends on what generator you used) and `Hello, World` should appear!   
- You know have a basic C++ with CMake environment setup    


### Renaming the Project

The first step you may want to do is rename the project.

- Open the CMakeList.txt and change the line that reads `project(ProjectName)` to `project(YourProjectName)`     
- In your terminal, in the project directory, run `cmake --build build --target clean` or delete the contents of the build folder    
- This has removed the old stuff from the build folder and built your new project    
- Now test the program by running `.\build\YourProjectName.exe` and you should get `Hello, World` back!
