cmake_minimum_required(VERSION 2.8.4)
project(experiment)

set(CXX_FLAGS
        -g
        -fPIC
        -Wall
        -std=c++11
        -DERROR_CODE_HEADER=105025
        )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_INSTALL_PREFIX "")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR})

add_executable(cache_line_test cache_line_test.cpp)