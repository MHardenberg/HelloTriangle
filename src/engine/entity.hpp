#pragma once
#include <array>
#include <cstddef>
//#include <MACROS.hpp>
#include "../MACROS/MACROS.hpp"
#include <cmath>

class Entity {
    public:
        const float width = 0.2f;
        const float height = 0.2f;
        std::array<float, 2> velocity {0.0f, 0.0f};
        std::array<float, 2> pos {0.0f, 0.0f};
        const float* vertices_prt;
        std::array<float, 9> vertices {
             0.0f, 0.0f, 0.0f,
             0.0f, 0.0f, 0.0f,
             0.0f, 0.0f, 0.0f
        }; 

    private:
        std::array<size_t, 3> x_idx = {0, 3, 6};
        std::array<size_t, 3> y_idx = {1, 4, 7};
        std::array<size_t, 3> z_idx = {2, 5, 8};

        const float hLimUpper = 1 - this->width/2;
        const float hLimLower = -1 + this->width/2;
        const float vLimUpper = 2;
        const float vLimLower = -1 + this->height/2 + 0.1;

    public: 
        Entity(){
            vertices_prt = vertices.data();
            this->update(0);
        }

        void update(float milliseconds); 
        void hTranslate(float x); 
        void vTranslate(float y); 
        bool onSurface() {
            return (this->pos[1] == this->vLimLower);
        }


    private:
        void gravity(float milliseconds); 
        void friction(float milliseconds);
        void updateVertices(); 
};
