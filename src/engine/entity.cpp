#include "entity.hpp"

void Entity::update(float milliseconds) {
    this->gravity(milliseconds);        
    this->friction(milliseconds);        

    this->hTranslate(this->velocity[0] * milliseconds / 1e3);
    this->vTranslate(this->velocity[1] * milliseconds / 1e3);
    this->updateVertices();
}


void Entity::gravity (float milliseconds) {
    static float g = CONSTANT_G;
    if (this->pos[1] == this->vLimLower) {return;}
    this->velocity[1] -= g*milliseconds / 1e3;
}

void Entity::friction(float milliseconds) {
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


void Entity::hTranslate(float x) {
    float hPos = this->pos[0] + x;
    if (hPos > this->hLimLower and hPos < this->hLimUpper) 
        {this->pos[0] = hPos; return;}
    
    // else negate velocity
    this->velocity[0] = 0;

    if (this->pos[0] < 0) {this->pos[0] = hLimLower;}
    if (this->pos[0] > 0) {this->pos[0] = hLimUpper;}
}               

void Entity::vTranslate(float y) {
    float vPos = this->pos[1] + y;
    if (vPos > this->vLimLower and vPos < this->vLimUpper)
        {this->pos[1] = vPos; return;}

    // else negate velocity
    this->velocity[1] = 0;

    if (this->pos[1] < 0) {this->pos[1] = vLimLower;}
    if (this->pos[1] > 0) {this->pos[1] = vLimUpper;}
}


void Entity::updateVertices () {
    this->vertices[x_idx[0]] = this->pos[0] - this->width/2;
    this->vertices[x_idx[1]] = this->pos[0] + this->width/2;
    this->vertices[x_idx[2]] = this->pos[0];

    this->vertices[y_idx[0]] = this->pos[1] - this->height/2;
    this->vertices[y_idx[1]] = this->pos[1] - this->height/2;
    this->vertices[y_idx[2]] = this->pos[1] + this->height/2;
}
