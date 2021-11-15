cmake_minimum_required(VERSION 3.0.0)

project(ProjectName)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

add_executable(${PROJECT_NAME} ${all_SRCS})

