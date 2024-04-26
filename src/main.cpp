#include <GLFW/glfw3.h>
#include <memory>

int main(void) {

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* glfwWindow = glfwCreateWindow(640, 480, "Hello World",
            glfwGetPrimaryMonitor(), NULL);


    if (!glfwWindow) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(glfwWindow);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(glfwWindow)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(glfwWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
