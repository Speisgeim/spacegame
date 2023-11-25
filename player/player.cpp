#include "raylib.h"
#include "raymath.h"

class Player{
public:
    Vector2 position;
    Vector2 velocity;
    Texture playerTexture;
    int angle;
    float power;

    Player(Vector2 position){
        this->position = position;
        velocity = {0, 0};
        playerTexture = LoadTexture("palyer.png");
        angle = 0;
        power = 0.1;
    }

    void Update(){


         if (IsKeyDown(KEY_W)) {
            // Convert angle to radians for trigonometric functions
            float radians = (float)angle * DEG2RAD;

            // Calculate the components of velocity based on the angle
            velocity.x += power * sinf(radians);
            velocity.y -= power * cosf(radians);
        }
        if (IsKeyDown(KEY_S)){
                        // Convert angle to radians for trigonometric functions
            float radians = (float)(angle-180) * DEG2RAD;

            // Calculate the components of velocity based on the angle
            velocity.x += power * sinf(radians);
            velocity.y -= power * cosf(radians);
        }
        if (IsKeyDown(KEY_A)){
            angle -= 2;            
        }
        if (IsKeyDown(KEY_D)){
            angle += 2;
        }

      
        
        velocity.x *= 0.995f;
        velocity.y *= 0.995f;

        position.x += velocity.x;
        position.y += velocity.y;



        Rectangle sourceRec = { 0.0f, 0.0f, (float)playerTexture.width, (float)playerTexture.height };
        Rectangle destRec = {position.x, position.y, (float)playerTexture.width, (float)playerTexture.height };
        Vector2 origin = { (float)playerTexture.width / 2.0f, (float)playerTexture.height / 2.0f };
        DrawTexturePro(playerTexture, sourceRec, destRec, origin, angle, WHITE);
    }

private:


};
