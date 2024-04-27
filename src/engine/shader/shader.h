#pragma once
//#include <glad/glad.h>
#include "../../../external/GLAD/include/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
//#include <MACROS.hpp>
#include "../../MACROS/MACROS.hpp"


namespace shader {
    struct GLSource {
        // This is the siuce code for various shaders. It is in ope
        const char *vertexShader = 
            "#version 460 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main() {\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

        const char* fragmentShader =
            "#version 330 core\n"
            "out vec4 FragColor\n;"
            "void main() {\n"
            "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\0";
    };


    struct Shader {
         unsigned int vertexShader;
         GLSource source;

        void compile() {
            // init and compile shader
            vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &source.vertexShader, NULL);
            glCompileShader(vertexShader);

            // check if compiled succesfully
            int  success;
            char infoLog[512];
            glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
            if(!success) {
                glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
                LOG_M("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                        << infoLog);
            }
        }
    };
};
