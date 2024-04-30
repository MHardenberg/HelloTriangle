#pragma once
#include <array>
#include <cstddef>


class Entity {
    public:
        std::array<float, 9> vertices {
            -0.1f, -0.1f, 0.0f,
             0.1f, -0.1f, 0.0f,
             0.0f,  0.1f, 0.0f
        }; 
        
        const float* vertices_prt;
    private:
        std::array<size_t, 3> x_pos = {0, 3, 6};
        std::array<size_t, 3> y_pos = {1, 4, 7};
        std::array<size_t, 3> z_pos = {2, 5, 8};

    public: 
        Entity(){
            vertices_prt = vertices.data();
        }

        void translate(float x, float y) {

                for (size_t i: x_pos) {
                        vertices[i] += x;
                }
                

                for (size_t j: y_pos) {
                        vertices[j] += y;
                    }
        }
        
};
