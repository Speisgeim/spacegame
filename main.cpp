#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 600;

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;



    InitWindow(screenWidth, screenHeight, "Speis");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(BLACK);
        



            EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}