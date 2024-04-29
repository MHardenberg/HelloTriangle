#include "shader.hpp"

int shader::compileShader(){
    int out = 0;
    unsigned int shaderProgram;
    GLSource source;
    unsigned int vertexShader, fragmentShader;
    // init and compile shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &source.vertexShader, NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &source.fragmentShader, NULL);
    glCompileShader(fragmentShader);

    // check if compiled succesfully
    int  success;
    char infoLog[512];

    for (auto s: {vertexShader, fragmentShader}) {
        glGetShaderiv(s, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(s, 512, NULL, infoLog);
            LOG_M("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
            << infoLog);
            goto cleanup;
            out = 1;
        }
    }

    // create shader program
    shaderProgram = glCreateProgram();
    for (auto s: {vertexShader, fragmentShader}) {
        glAttachShader(shaderProgram, s);
    }

    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        LOG_M("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
        << infoLog);
        goto cleanup;
        out = 1;
    }

    glUseProgram(shaderProgram);

    cleanup:
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

    return out;
}
