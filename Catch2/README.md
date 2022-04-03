# Catch2
This repo is a simple project template for C/C++ to get your project up and running using CMake and VSCode whilst also providing access to the [Catch2](https://github.com/catchorg/Catch2) unit test framework. 

This project uses CMake and therefore the file type (.c or .cpp) dictates which compiler is used. By default this project is set to C++ but can be changed to C by changing `main.c` to `main.cpp`. Make sure you update your [CMakeLists.txt with the new file name](../README.md#adding-new-files). Note Catch2 is a C++ framework and needs to be compiled with C++.

## Compiler, Build and VSCode

To get this program up and running just follow the instructions in the [Main README](../README.md). 

Once you have followed all the steps and run the program you'll see `Hello, World, 1 + 1 = 2` and `RELEASE BUILD`/`DEBUG BUILD`.

You are now setup to start your C/C++ project!

## Adding Unit Tests
To add a unit test, create a file in the `tests` folder and add the file to the `CMakeLists.txt` next to the other test files. Then follow the instructions on the [[Catch2 Github](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#writing-tests)] on how to write tests. Due to integration with CMake these will be added to CTest and can be run through the VSCode CMake Extension using the CTest button on the bottom tool bar. 

## End Note
This repo is designed to help people new to C/C++ get started. I'm still fairly new to CMake, C++ and Open Source project. I would love any feedback, so please raise an Issue on the Github page if you have any! If you have any issues with the steps in this repo, just create an issue on Github and I'll do my best to help!
