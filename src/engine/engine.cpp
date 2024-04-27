#include "engine.hpp"
#include "shaders/vertexShader.h"


Engine::Engine() {
    if (!glfwInit()) {LOG_M("glfw initalisation failed."); return;}
    this->glfwInitialised = true;

    // create window
    this->glfwWindow = glfwCreateWindow(this->WIDTH, this->HEIGHT,
            "Hello World", glfwGetPrimaryMonitor(), NULL);

    // manage context ~ whatever that means.....
    glfwMakeContextCurrent(glfwWindow);
    gladLoadGL();
    LOG_M("OpenGL version: " << glGetString(GL_VERSION));

    // set viewport for scaling
    glViewport(0, 0, this->WIDTH, this->HEIGHT);


    // init VBO
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // binds it to array buff

    // init and compile shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check if compiled succesfully
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LOG_M("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
    }
}


Engine::~Engine() {
        glfwTerminate();
    }


void Engine::run() {
    if (!this->glfwInitialised) {return;}

    // populate enteties
    Entity triangle;

    while (!glfwWindowShouldClose(glfwWindow)) {
    // process input and act
        this->processInput();




    // Render here
        //glClear(GL_COLOR_BUFFER_BIT);
        //copy data to buff
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle.vertices), 
                triangle.vertices, GL_STATIC_DRAW);

        /*
            GL_STREAM_DRAW: the data is set only once and used by the GPU 
                at most a few times.
            GL_STATIC_DRAW: the data is set only once and used many times.
            GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
         */


    // Poll for and process events
        glfwPollEvents();

    // Swap front and back buffers
        glfwSwapBuffers(glfwWindow);

    }
}

void Engine::processInput() {
    if (glfwGetKey(this->glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //glfwSetWindowShouldClose(this->glfwWindow, true);
    }
}
