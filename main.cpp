#include "raylib.h"

#define MAX_COLUMNS 20

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");
    SetTargetFPS(60);

    Texture2D scarfy = LoadTexture("textures/scarfy.png");

    float x = 32.0f, y = 32.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            if(IsKeyDown(KEY_D)) {
                x += GetFrameTime() * 100.0f;
            }

            if(IsKeyDown(KEY_A)) {
                x -= GetFrameTime() * 100.0f;
            }

            if(IsKeyDown(KEY_S)) {
                y += GetFrameTime() * 100.0f;
            }

            if(IsKeyDown(KEY_W)) {
                y -= GetFrameTime() * 100.0f;
            }


            DrawTexturePro(
                scarfy,
                Rectangle {0, 0 , 128, 128},
                Rectangle {x, y, 128, 128},
                Vector2 {0, 0},
                0,
                RAYWHITE
            );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}