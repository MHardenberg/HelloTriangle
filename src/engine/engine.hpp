#pragma once
//#include <glad/glad.h>
#include "../../external/GLAD/include/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
//#include <MACROS.hpp>
#include "../MACROS/MACROS.hpp"
#include "entity.hpp"
#include <chrono>
#include <thread>


class Clock {
    public:
        std::chrono::milliseconds deltaTime = 
            std::chrono::milliseconds(this->milliseconds);
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> now;
        constexpr static long milliseconds = (long)(1000./ 60);

    public:
        void mark() {
            now = std::chrono::high_resolution_clock::now();
        }

        void idle() {
            auto start = this->now;
            this->mark();
            auto time = 
                std::chrono::duration_cast<std::chrono::milliseconds> 
                (this-> now - start);

            std::this_thread::sleep_for(deltaTime - time);
        }
};

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
        
        Clock clock;
        
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
