cmake_minimum_required(VERSION 3.21)

# Config
project(UnitTest VERSION 1.0.0 LANGUAGES C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source
# It is recommanded to manually add source files vs GOB
set(SOURCES_APP 
src/foo.cpp
)
set(HEADERS_APP 
inc/foo.hpp
)

# Create lib with non main.cpp sources
set(APP_LIB app)
add_library (${APP_LIB} ${SOURCES_APP} ${HEADERS_APP})
target_include_directories(${APP_LIB} PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Link lib to project executable and add main.cpp
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries (${PROJECT_NAME} ${APP_LIB})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Libraries
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)
FetchContent_MakeAvailable(Catch2)

# Testing
enable_testing()
set(TESTS_NAME test_exe)

# Test Source Files
set(SOURCES_TEST
tests/t_foo.cpp
)

# Create Test executable
add_executable(${TESTS_NAME} ${SOURCES_TEST})
target_link_libraries(${TESTS_NAME} 
    PRIVATE ${APP_LIB}
    PRIVATE Catch2::Catch2WithMain
)
target_include_directories(${TESTS_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Add to CTest
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(${TESTS_NAME})

# Options
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-DDEBUG>)