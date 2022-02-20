# CppTemplate

This repo is a collection of templates for different types of C++ projects for my own and others reference. All the templates are independent but generalized instructions on how to get started are below. The setup instructions are currently only for Windows but can be adapted for other platforms, please reach out if you need help. 

Extra information about the individual projects are in the README of each folder.

- [Basic](Basic) - A bare-bones C/C++ (C++ by default) project template. 
- [Raylib](Raylib) - A simple and easy to use raylib C/C++ (C by default) project template.


## Setup (Windows)
### Compiler
We are going to using GCC (G++) as our compiler. I've found that the best way to get GCC on Windows is using MSYS2. If you have GCC installed or another compiler like MVSC or Clang, you can skip this step. (This guide is heavily based on of [this guide on 
stackoverflow](https://stackoverflow.com/questions/30069830/how-to-install-mingw-w64-and-msys2)).

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
- If this doesn't provide output with a gcc version try repeating the above steps or create an issue in this repo. 

You now have your compiler install, to allow you access it anywhere without needing to provide its location add `<MSYS2 root>/mingw64/bin` or `<MSYS2 root>/mingw32/bin` (for 32 bit machines) to your PATH. This guide will assume that you have done this. 

### Build Tools and Version Control
Now we have our compiler working, we need the tools to build our programs. Compiling a program can be done by hand directly via the compiler's command line arguments however that gets boring fast. I do suggest you [look into how you compile programs without build tools](https://youtu.be/2YfM-HxQd_8?t=19) as it will help your understanding but it's generally not recommended for everyday use. 

There are a couple of other programs required:
- [CMake](https://cmake.org/download/) - CMake it self.
- [Git for Windows](https://gitforwindows.org/) - Our version control (Optional but recommended). 

During this process, CMake will ask if you want it added to PATH, click yes as it will it make it a lot easier to run commands (and this guide will assume you have).    

Note: You need to download these for your Host OS, do not install them through MSYS2 as it will not work correctly.


## Downloading the Code
First we need to get the project template onto our local machine. This can be done two ways, either by downloading the repo from the Github website or git.

### In Browser
- Go to the [repo page](https://github.com/ArchieAtkinson/CppTemplate).
- Click the `Code` button.
- Download zip.
- Once downloaded extract the zip.
- Move the folder of the project template you want to use somewhere suitable.
- You are ready to go.

### Git
- Open Git Bash or your terminal.
- Navigate to where you would like the repo stored.
- Then clone the whole repo it with the following command:  
  - `git clone https://github.com/ArchieAtkinson/CppTemplate.git` 
- Feels free to delete the project template folders you don't need. 
- You are ready to go.
   

## Building and Running the Code 
To build and run your code you have two options. Either using the CMake command line interface or using an IDE, which in this case will be VSCode. I suggest reading through command line setup so you understand whats going under the hood as your IDE will be running the same (or very similar) commands, just in the background. 

### Command Line

- The first step is to open a terminal and navigate inside the project folder you would like to use. 
- Create a build directory with:
    - `mkdir build`    
- Configure your CMake:
    - `cmake -S . -B build`
- To create a debug build just add the below flag to the end of the previous command:
  -  `-DCMAKE_BUILD_TYPE=Debug`  
- Now to build the project:
  - `cmake --build build`    
- If everything has gone to plan you can now run the binary with:
  -  `.\build\ProjectName.exe`
 
You now have a basic C/C++ with CMake environment setup.

### VSCode
VSCode is a great text editor that can be used as development environment on any of the main platforms (Windows, macOS and Linux) and for almost any language. I suggest you dig further into [VSCode](https://code.visualstudio.com/docs/introvideos/basics) and [CMake](https://www.youtube.com/watch?v=_yFPO1ofyF0&list=PLK6MXr8gasrGmIiSuVQXpfFuE1uPT615s) once you have everything setup as it will definitely help you out in the future. 

Note: Visual Studio Code (VSCode) is not the same as [Visual Studio](https://visualstudio.microsoft.com/). One is a general purpose code editor (that can be turned into a lightweight IDE, which is what we will be doing) and the other is a fully packed IDE for developing on Windows. 

- [Download VSCode](https://code.visualstudio.com/) if you haven't.
- Once downloaded, go the extensions tab of the left and install the following extensions:
    - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
    - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- Now open the directory of the the project folder you would like to use.
- If asked "Would you like to configure project '<ProjectName>'? Click `Yes` 
- You should now be able to see bar at bottom, shown below.   
    - The `Build Type` button lets you set your build for release or debug (or any other builds you want to support).
    - The `Kit` button lets you set your compiler, if you are following this guide on Windows you want to select the GCC...mingw32 option.
    - The `Build` button starts a build.
    - The `Debug` button starts a debugging session (It builds first, then launches the debugger).
    - The `Run` button starts the programing normally (It builds first, then launches).
    - These can all be bound to a key, see File->Preference->Keyboard Shortcuts.
    - You should now be able to click the "Run" button to compile and launch your program. 
  
![Annotated image of the cmake bar at the bottom left of VSCode](repo_assets/CMake_Bar.png)


You now have a basic C/C++ with CMake environment setup.

## Renaming the Project
Now you have the demo code compiling, you may want to start developing your own project. Well the first step is setting a name. To do so you only need to change one bit of text:   
- Open the `CMakeLists.txt` file.
  - This is where all the configuration information lives.
- Near the top there is a line that reads:
  - `project(ProjectName VERSION 1.0.0 LANGUAGES C CXX ASM)`
- Just change where is says `ProjectName` to what ever you want you project to be called!
  - I would suggest not including spaces or any of the following characters `*"\/<>:|?` to prevent possible issues.
- As this changes the build files CMake generates, we need to clean the build files.
- Command Line Method:
  - First clean the build folder:
    - `cmake --build build --target clean`
  - Then rebuild the program:
    - `cmake --build build`
  - Now you can run it
    - `.\build\YourNewProjectName.exe`
- VSCode Method
  - Use the keyboard shortcut to bring up the Command Pallette:
    - `Ctrl + Shift + P`
  - Now we will force CMake to clean and rebuild by typing:
    - `Cmake: Clean Rebuild` and pressing enter
  - You can now run it by clicking the `Run` button


## Adding New Files
If you want to organize your code into multiply files, you need to let CMake know. Every file you use needs to be added to your CMakeList.txt. 
- Open `CMakeList.txt`.
- Go to the `Sources` section.
- You can see two functions, one for `SOURCES` and one for `HEADERS`.
- Source files (.c or .cpp) go under `SOURCES` and header files (.h or .hpp) go under `HEADERS`.
- Just create a newline under the respective function and add the path to your file.
- Rebuild and Run!

## Troubleshooting

### `No useable generator found` error:
- Command Line:
  - We can specify the generator to help it find it
    - `cmake -S . -B build -G "MinGW Makefiles"`
  - You can continue the build process.
- VSCode (Windows)
  - File->Preference->Settings.
  - Search `generator`.
  - Add `MinGW Makefiles` to the `Cmake: Generator` field.
  - Use the keyboard shortcut to bring up the Command Pallette:
    - `Ctrl + Shift + P`
  - Now we will force CMake to reconfigure by typing:
    - `Cmake: Configure` and press enter
  - You can now continue the guide.
Note: On other platforms the same steps work but the generator name will be different.

### Debugging isn't working
- Ensure your build is set to Debug while debugging or the debugger will not work.

### I was not asked "Would you like to configure project 'CppTemplate'?" when loading the project in VSCode.
- Use the keyboard shortcut to bring up the Command Pallette:
  - `Ctrl + Shift + P`
- Now we will force CMake to configure by typing:
  - `Cmake: Configure` and press enter
- You can now continue the guide.



## End Note
This repo is designed to help people new to C/C++ get started. I'm still fairly new to CMake, C++ and Open Source project. I would love any feedback, so please raise an Issue on the Github page if you have any! If you have any issues with the steps in this repo, just create an issue on Github and I'll do my best to help!

