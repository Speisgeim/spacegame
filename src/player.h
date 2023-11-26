#pragma once

#include <raylib.h>
#include <raymath.h>


class Player {
public:
    Vector2 position;
    Vector2 velocity;
    Texture playerTexture;
    int angle;
    float power;

    Player(Vector2 position);

    void Update();

    
};

