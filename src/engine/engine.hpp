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
        Engine() {
            if (!glfwInit()) {LOG_M("glfw initalisation failed."); return;}
            this->glfwInitialised = true;

            // create window
            this->glfwWindow = glfwCreateWindow(this->WIDTH, this->HEIGHT,
                    "Hello World", glfwGetPrimaryMonitor(), NULL);

            // manage context ~ whatever that means.....
            glfwMakeContextCurrent(glfwWindow);
            gladLoadGL();
            LOG_M("OpenGL version: %s\n" << glGetString(GL_VERSION));

            // set viewport for scaling
            glViewport(0, 0, this->WIDTH, this->HEIGHT);
        }

        ~Engine() {
            glfwTerminate();
        }

        void render() {
            if (!this->glfwInitialised) {return;}
            while (!glfwWindowShouldClose(glfwWindow)) {
                /* Render here */
                glClear(GL_COLOR_BUFFER_BIT);

                /* Swap front and back buffers */
                glfwSwapBuffers(glfwWindow);

                /* Poll for and process events */
                glfwPollEvents();
            }
        }
};
