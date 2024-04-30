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


    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    }


Engine::~Engine() {
        glfwTerminate();
    }


void Engine::run() {
    if (!this->glfwInitialised) {return;}

    // populate enteties
    Entity triangle;
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle.vertices), 
            triangle.vertices, GL_STATIC_DRAW);
        /*
            GL_STREAM_DRAW: the data is set only once and used by the GPU 
                at most a few times.
            GL_STATIC_DRAW: the data is set only once and used many times.
            GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
         */
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  


    while (!glfwWindowShouldClose(glfwWindow)) {
    // process input and act
        this->processInput();




    // Render here
        //glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(this->shaderProgram);
        glBindVertexArray(this->VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

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
