#include "star.h"



Star::Star(Vector2 position, int size){
    this->position = position;
    this->size = size;
}

void Star::Draw(){
    DrawRectangleV(position, Vector2{(float)size,(float)size}, WHITE);
}

