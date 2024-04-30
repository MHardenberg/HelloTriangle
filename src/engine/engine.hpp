#pragma once
//#include <glad/glad.h>
#include "../../external/GLAD/include/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
//#include <MACROS.hpp>
#include "../MACROS/MACROS.hpp"
#include "entity.hpp"
#include "gameClock.hpp"


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
        bool shaderCompiled = false;
        enum class renderMode {staticRender, streamRender, dynamicRender};

        Entity player;
        float moveIncrement = 0.025f;
        float velIncrement = 0.025f;
        
        GameClock clock;
        
    public:
        Engine();
        ~Engine();

        void run();
    private:
        void processVertices(Entity entity, renderMode mode);
        void processInput();

        void idle() {
            
        }
};
