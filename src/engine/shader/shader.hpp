#pragma once
//#include <glad/glad.h>
#include "../../../external/GLAD/include/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
//#include <MACROS.hpp>
#include "../../MACROS/MACROS.hpp"


namespace shader {
    struct GLSource {
// This is the source code for various shaders. It is in OpenGL Shader lang.
// These have to be compiled and liked into a shader program.
        const char *vertexShader = 
            "#version 460 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main() {\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";


// Colors in computer graphics are represented as an array of 4 values:
// the red, green, blue and alpha (opacity) component, commonly abbreviated to 
// RGBA. When defining a color in OpenGL or GLSL we set the strength of each
// component to a value between 0.0 and 1.0. If, for example, we would set red
// to 1.0 and green to 1.0 we would get a mixture of both colors and get the 
// color yellow.

        const char* fragmentShader =
            "#version 460 core\n"
            "out vec4 FragColor\n;"
            "void main() {\n"
            "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\0";
    };
    int compileShader ();
}
