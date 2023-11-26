#include <iostream>
#include <raylib.h>
#include "map.cpp"
#include "player.h"
#include <string>

int main () {

    const int screenWidth = 1200;
    const int screenHeight = 1000;


    InitWindow(screenWidth, screenHeight, "Speis");
    SetTargetFPS(155);


    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;



    Map map(1);


    Player player((Vector2){0,0});



    while (WindowShouldClose() == false){
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
        
                map.Update(player.position);

                player.Update();
                camera.target = player.position;




            EndMode2D();

            std::string myString = std::to_string(GetFPS());
            const char *myCString = myString.c_str();
            DrawText(myCString, 10,10,10,GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}