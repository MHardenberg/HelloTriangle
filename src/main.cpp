#include "../include/glad/include/glad/gl.h"
#include <GLFW/glfw3.h>
#include <iostream>

#define projectName "Hello Triangle!!"

int main () {
    std::cout << "Hello triangle!!" << std::endl;


    // init glfw and use version 3.3, with OPENGL, OPENGL_CORE
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // create window
    GLFWwindow* window = glfwCreateWindow(800, 600, projectName, nullptr, 
            nullptr);
    if (window ==  nullptr) {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return 1;
    }

    // context of current thread
    glfwMakeContextCurrent(window);


    // glad setup
    //if (!gladLoadGLLoader) // fix this? wrong import??
    return 0;
}
