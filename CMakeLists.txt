cmake_minimum_required(VERSION 3.5)
project(HelloTriangle)

# Building
set(CMAKE_BUILD_TYPE "Debug")

# Common settings
set(CMAKE_CC_COMPILER gcc)
set(CMAKE_CC_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -Iglad/include")
set(CMAKE_EXE_LINKER_FLAGS "-lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl")
set(SOURCES src/main.cpp include/glad/src/gl.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glad/include)
file(GLOB BUTTERFLIES_SOURCES_C ${CMAKE_CURRENT_SOURCE_DIR} *.c include/glad/src/gl.c)

# Build specific settings
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fsanitize=address -O1 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -s")


# Executable
add_executable(main.out ${SOURCES})
