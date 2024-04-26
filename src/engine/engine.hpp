#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../MACROS.hpp"


class Engine {
    public:
        const unsigned int WIDTH = 600, HEIGHT = 400;

    private:
        GLFWwindow* glfwWindow;
        bool glfwInitialised = false;
    
    public:
        Engine() {
            if (!glfwInit()) {LOG("glfw initalisation failed."); return;}
            this->glfwInitialised = true;

            // create window
            this->glfwWindow = glfwCreateWindow(this->WIDTH, this->HEIGHT,
                    "Hello World", glfwGetPrimaryMonitor(), NULL);

            // manage context ~ whatever that means.....
            glfwMakeContextCurrent(glfwWindow);
            gladLoadGL();
            LOG("OpenGL version: %s\n" << glGetString(GL_VERSION));
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
