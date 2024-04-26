cmake_minimum_required(VERSION 3.5)
project(HelloTriangle)

# Building
set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_BUILD_TYPE "Release")

# Common settings
set(CMAKE_CC_COMPILER gcc)
set(CMAKE_CC_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra ")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fsanitize=address -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -s")


# Find OpenGL package
find_package(OpenGL REQUIRED)

# GLFW settings
add_subdirectory(external/GLFW)  
include_directories(external/GLFW/include)

# Executable sources
set(SOURCES src/main.cpp)

# Executable
add_executable(HelloTriangle ${SOURCES})

# Link GLFW and OpenGL
target_link_libraries(HelloTriangle PRIVATE glfw OpenGL::GL)

