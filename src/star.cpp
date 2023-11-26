#include <raylib.h>

class Star{

public:
    Vector2 position;
    int size;

    Star(Vector2 position, int size){
        this->position = position;
        this->size = size;
    }

    void Draw(){
        DrawRectangleV(position, Vector2{(float)size,(float)size}, WHITE);
    }

private:

};