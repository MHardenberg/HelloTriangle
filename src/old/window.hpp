#pragma once
#define projectName "Hello Triangle!!"

#include "../include/glad/include/glad/gl.h"
#include <GLFW/glfw3.h>


class Window {
    private:
        const unsigned int HEIGHT = 600, WIDTH = 800; 
        GLFWwindow* glfwWindow;

    public:
        Window();
        ~Window();
        void render();

    private:
        void processInput();
        void clear(); 
};
