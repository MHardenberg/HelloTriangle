#include "engine.hpp"
#include "shader/shader.hpp"


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
    

    // init shaders
    shader::Shader shader;
    this->shaderProgram = shader.compile();
    this->shaderCompiled = shader.success;


    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    }


Engine::~Engine() {
        glfwTerminate();
    }


void Engine::processVertices(Entity entity, renderMode mode) {
    unsigned int drawMode;

    switch (mode) {
        /*
            GL_STREAM_DRAW: the data is set only once and used by the GPU 
                at most a few times.
            GL_STATIC_DRAW: the data is set only once and used many times.
            GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
         */

        case renderMode::staticRender: {
            drawMode = GL_STATIC_DRAW;
            break;
                                       }
        case renderMode::streamRender: {
            drawMode = GL_STREAM_DRAW;
            break;
                                       }
        case renderMode::dynamicRender: {
            drawMode = GL_DYNAMIC_DRAW;
            break;
                                       }
        default: {
            drawMode = GL_STATIC_DRAW;
            break;
                 }

                                        
    }

    // copy vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(entity.vertices), 
            entity.vertices_prt, drawMode);

    // then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
            3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    // render triangles
    glUseProgram(this->shaderProgram);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void Engine::run() {
    if (!this->glfwInitialised or !this->shaderCompiled) {return;}

    // populate entities

    while (!glfwWindowShouldClose(glfwWindow)) {
    // process input and act
        this->clock.mark();
        glClear(GL_COLOR_BUFFER_BIT);
        processVertices(this->player, renderMode::dynamicRender);
       this->processInput();

       this->clock.idle();

    // Render here
        
    // Poll for and process events
        glfwPollEvents();

    // Swap front and back buffers
        glfwSwapBuffers(glfwWindow);

    }
}


void Engine::processInput() {
    // motion
    if (glfwGetKey(this->glfwWindow, GLFW_KEY_D) == GLFW_PRESS) {
        this->player.velocity[0] += this->velIncrement;
    }
    if (glfwGetKey(this->glfwWindow, GLFW_KEY_A) == GLFW_PRESS) {
        this->player.velocity[0] -= this->velIncrement;
    }

    if (glfwGetKey(this->glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->glfwWindow, true);
    }

    //jumping 
    if (glfwGetKey(this->glfwWindow, GLFW_KEY_SPACE) == GLFW_PRESS) {
        this->player.velocity[1] += this->velIncrement * 10;
    }

    this->player.update(this->clock.dtMilli);
}
