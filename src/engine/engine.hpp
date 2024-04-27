#pragma once
//#include <glad/glad.h>
#include "../../external/GLAD/include/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
//#include <MACROS.hpp>
#include "../MACROS/MACROS.hpp"
#include "entity.hpp"


class Engine {
    public:
        const unsigned int WIDTH = 600, HEIGHT = 400;

    private:
        GLFWwindow* glfwWindow;
        bool glfwInitialised = false;
        unsigned int VBO;  // vertex buffer object - here we send vertices to 
                           // gpu mem
         unsigned int vertexShader;
    public:
        Engine();
        ~Engine();

        void run();
    private:
        void processInput();
        void render() {

        }
};
