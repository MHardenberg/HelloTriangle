#include "shader.hpp"

unsigned int shader::Shader::compile(){
    unsigned int shaderProgram;

    // init and compile shader
    this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vertexShader, 1, &source.vertexShader, NULL);
    glCompileShader(this->vertexShader);

    this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragmentShader, 1, &source.fragmentShader, NULL);
    glCompileShader(this->fragmentShader);

    // check if compiled succesfully
    int  success;
    char infoLog[512];

    for (auto s: {this->vertexShader, this->fragmentShader}) {
        glGetShaderiv(s, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(s, 512, NULL, infoLog);
            LOG_M("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
            << infoLog);
        }
    }

    // create shader program
    shaderProgram = glCreateProgram();
    for (auto s: {this->vertexShader, this->fragmentShader}) {
        glAttachShader(shaderProgram, s);
    }

    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        LOG_M("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
        << infoLog);
    }

    glUseProgram(shaderProgram);
    return shaderProgram;
}
