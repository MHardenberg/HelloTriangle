#pragma once
//#include <glad/glad.h>
#include "../../external/GLAD/include/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
//#include <MACROS.hpp>
#include "../MACROS/MACROS.hpp"


class Engine {
    public:
        const unsigned int WIDTH = 600, HEIGHT = 400;

    private:
        GLFWwindow* glfwWindow;
        bool glfwInitialised = false;
    
    public:
        Engine();
        ~Engine();

        void render();
};
