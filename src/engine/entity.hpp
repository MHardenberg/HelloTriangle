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
            -this->width/2, 0.0f, 0.0f,
             this->width/2, 0.0f, 0.0f,
             0.0f,  this->height, 0.0f
        }; 

    private:
        std::array<size_t, 3> x_idx = {0, 3, 6};
        std::array<size_t, 3> y_idx = {1, 4, 7};
        std::array<size_t, 3> z_idx = {2, 5, 8};

        const float hLimUpper = 1 - this->width/2;
        const float hLimLower = -1 + this->width/2;
        const float vLimUpper = 1 - this->height/2;
        const float vLimLower = -1 + this->height/2;

    public: 
        Entity(){
            vertices_prt = vertices.data();
        }

        void update(float milliseconds); 
        void hTranslate(float x); 
        void vTranslate(float y); 
        bool onSurface() {
            return (this->pos[1] == this->vLimLower);
        }


    private:
        void gravity(float milliseconds); 
        void friction(float milliseconds) {
            static const float mu = CONSTANT_FRICTION;
            static const float g = CONSTANT_G;

            if (!this->onSurface()) {return;}
            // stays unmoving
            if (!this->velocity[0]) {return;}
    
            if (velocity[0] > 0) {
                this-> velocity[0] = 
                    std::max(0., velocity[0] - g * mu * milliseconds / 1e3);
            }
            if (velocity[0] < 0) {
                this-> velocity[0] = 
                    std::min(0., velocity[0] + g * mu * milliseconds / 1e3);
            }
        }
        void updateVertices(); 
};
