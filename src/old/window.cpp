#include "window.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>


Window::Window() {
    // init glfw and use version 3.3, with OPENGL, OPENGL_CORE
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // create window
    this->glfwWindow = glfwCreateWindow(this->WIDTH, this->HEIGHT,
            projectName, nullptr, nullptr);
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


Window::~Window() {
    glfwDestroyWindow(this->glfwWindow);
    glfwTerminate();
}


void Window::render() {
    // render loop
    while(!glfwWindowShouldClose(this->glfwWindow )) {
        this->processInput();
        glfwPollEvents();    
        glfwSwapBuffers(this->glfwWindow );
    }
}


void Window::processInput() {
    if (glfwGetKey(this->glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        this->clear();
    }
}


void Window::clear() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
}
