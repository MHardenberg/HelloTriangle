cmake_minimum_required(VERSION 3.5)
project(HelloTriangle)

# Building
set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

# dependencies
add_subdirectory(external/GLFW)  


# Executable sources
set(SOURCES 
    src/main.cpp 
    src/engine/engine.cpp
    src/engine/gameClock.cpp
    src/engine/entity.cpp
    src/engine/shader/shader.cpp
    external/GLAD/src/glad.c
    )


# Executable
add_executable(HelloTriangle ${SOURCES})

# Includes
target_include_directories(HelloTriangle PRIVATE 
    ${CMAKE_SOURCE_DIR}/external/GLAD/include/ 
    ${CMAKE_SOURCE_DIR}/external/GLFW/include/ 
    ${CMAKE_SOURCE_DIR}/src/MACROS/
    )

# Link GLFW and OpenGL
target_link_libraries(HelloTriangle PRIVATE glfw OpenGL::GL)

