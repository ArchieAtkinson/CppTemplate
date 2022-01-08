cmake_minimum_required(VERSION 3.21)

# Config
project(ProjectName VERSION 1.0.0 LANGUAGES C CXX ASM)

# Source
set(SOURCES 
src/main.cpp
)
set(HEADERS 
inc/header.h
)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Options
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-DDEBUG>)