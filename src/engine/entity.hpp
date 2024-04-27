#pragma once
#include <array>


class Entity {
    public:
        std::array<float, 9> vertices[9] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        }; 

};
