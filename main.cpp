#include "raylib.h"
#include "raymath.h"

#define MAX_COLUMNS 20

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera first person");
    SetTargetFPS(60);

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    unsigned numFrames = 6;
    int frameWidth = scarfy.width / numFrames;
    Vector2 scarfyPosition =  {10, 10};
    Rectangle frameRec = {0.0f, 0.0f, (float)frameWidth, (float)scarfy.height};
    Vector2 scarfyVelocity = {0, 0};

    float x = 32.0f, y = 32.0f;

    unsigned frameDelay = 5;
    unsigned frameDelayCounter = 0;
    unsigned frameIndex = 0;
    bool scarfyMoving = false;
    const int scarfySpeed = 5;


    while (!WindowShouldClose())
    {

        if(IsKeyDown(KEY_D)) {
            scarfyVelocity.x = scarfySpeed;
            if(frameRec.width < 0) {
                frameRec.width = -frameRec.width;
             }
        } else if(IsKeyDown(KEY_A)) {
             scarfyVelocity.x = -scarfySpeed;
             if(frameRec.width > 0) {
                frameRec.width = -frameRec.width;
             }
        } else {
            scarfyVelocity.x = 0;
        }
        

        scarfyMoving = scarfyVelocity.x != 0.0f || scarfyVelocity.y != 0.0f;

        scarfyPosition = Vector2Add(scarfyPosition, scarfyVelocity);

        frameDelayCounter++;
        if(frameDelayCounter >= frameDelay) {
            frameDelayCounter = 0;
            if(scarfyMoving) {
                frameIndex++;
                frameIndex %= numFrames;
                frameRec.x = (float)frameWidth * frameIndex;
            }
        }


        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTextureRec(scarfy, frameRec ,scarfyPosition, WHITE);

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


            // DrawTexturePro(
            //     scarfy,
            //     Rectangle {0, 0 , 300, 300},
            //     Rectangle {x, y, 300, 300},
            //     Vector2 {0, 0},
            //     0,
            //     RAYWHITE
            // );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}