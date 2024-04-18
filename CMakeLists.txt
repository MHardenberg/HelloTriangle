cmake_minimum_required(VERSION 3.5)
project(HelloTriangle)

# Building
set(CMAKE_BUILD_TYPE "Debug")

# Common settings
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -Wall -Wpedantic -Wextra)
set(SOURCES src/main.cpp)

# Build specific settings
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -OO -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -s")

# Executable
add_executable(main.out ${SOURCES})
