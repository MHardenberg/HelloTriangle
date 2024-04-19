#include "../include/glad/include/glad/gl.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

#define projectName "Hello Triangle!!"


class Window {
    private:
        const unsigned int HEIGHT = 600, WIDTH = 800; 
        GLFWwindow* glfwWindow;

    public:
        Window() {
            // init glfw and use version 3.3, with OPENGL, OPENGL_CORE
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            // create window
            this->glfwWindow = glfwCreateWindow(this->WIDTH, this->HEIGHT,
                    projectName, nullptr, 
                    nullptr);
            if (this->glfwWindow  ==  nullptr) {
                std::cerr << "Failed to create window" << std::endl;
                throw std::runtime_error("Could noit create window.");
            }

            // context of current thread
            glfwMakeContextCurrent(this->glfwWindow );


            // glad setup
            gladLoadGL(glfwGetProcAddress);

            // viewport
            glViewport(0, 0, this->WIDTH, this->HEIGHT);
        }

        void render() {
            // render loop
            while(!glfwWindowShouldClose(this->glfwWindow )) {
                glfwSwapBuffers(this->glfwWindow );
                glfwPollEvents();    
                this->processInput();
            }
        }

        ~Window() {
            glfwTerminate();
        }

    private:
        void processInput() {
            if (glfwGetKey(this->glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                this->clear();
            }
        }

        void clear() {
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
        }
};


int main () {
    std::cout << "Hello triangle!!" << std::endl;
    Window window;
    window.render();




    



    // clean up
    return 0;
}
