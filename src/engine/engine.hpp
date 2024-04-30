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
        const unsigned int WIDTH = 1920, HEIGHT = 1080;

    private:
        GLFWwindow* glfwWindow;
        bool glfwInitialised = false;
        unsigned int VBO;  // vertex buffer object - here we send vertices to 
                           // gpu mem
        unsigned int VAO; // vertex array object
        unsigned int shaderProgram;
        
    public:
        Engine();
        ~Engine();

        void run();
    private:
        void processInput();
        void render() {

        }
};
