# Raylib
This repo is a simple template to help you get your [raylib](https://www.raylib.com/index.html) C/C++ project up and running using CMake and VSCode. No need to download raylib, just follow the instructions below and it will set everything up for you. 

This system uses CMake and therefore the file type (.c or .cpp) dictates which compiler is used. By default this project is set to C due to raylib being a C library but can be changed to C++ by renaming `main.c` to `main.cpp`. Make sure you update your [CMakeList.txt with the new file name](../README.md#adding-new-files).

This repo is using the [basic window](https://github.com/raysan5/raylib/blob/master/examples/core/core_basic_window.c) example provided in the [raylib repo](https://github.com/raysan5/raylib) as a starting point.  

## Compiler, Build and VSCode

To get this program up and running just follow the instructions in the [Main README](../README.md) for this repo. 

Note: The configuring CMake step may take a couple of minutes as it needs to download the raylib repo. 

Once you have followed the steps you should and run the program, you should see a window displaying `"Congrats! You created your first window!"`.   

You are now setup to start your raylib project!

## End Note
This repo is designed to help people new to C/C++ get started. I'm still fairly new to CMake, C++ and Open Source project. I would love any feedback, so please raise an Issue on the Github page if you have any! If you have any issues with the steps in this repo, just create an issue on Github and I'll do my best to help!