#include "entity.hpp"


void Entity::hTranslate(float x) {
    for (size_t i: x_pos) {
            vertices[i] += x;
    }
}               

void Entity::vTranslate(float y) {
    for (size_t j: y_pos) {
            vertices[j] += y;
        }
}
