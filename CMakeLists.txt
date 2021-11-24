cmake_minimum_required(VERSION 3.7...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(ProjectName)
enable_language( C CXX ASM )

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME} "src/main.cpp") # It is recommanded to manually add source files.

set(CMAKE_CXX_STANDARD 17)

# add_subdirectory(path/to/library)
# target_link_libraries(${PROJECT_NAME} PRIVATE libname)