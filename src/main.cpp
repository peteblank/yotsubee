/*******************************************************************************************
*
*   raylib [textures] example - Sprite animation
*
*   Example originally created with raylib 1.3, last time updated with raylib 1.3
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "../include/raylib.h"

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [texture] example - sprite anim");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
<<<<<<< HEAD
    Texture2D scarfy = LoadTexture("src/assets/Yotsuba_SpriteSheet.png");        // Texture loading
/*
fixed the path
=======
    Texture2D yotsuba = LoadTexture("src/assets/Yotsuba_SpriteSheet.png");        // Texture loading
>>>>>>> f54f407f730a43893f37d09d56a7073716329d74

    
    Vector2 position = { 350.0f, 280.0f };
<<<<<<< HEAD
    Rectangle frameRec = { (float)scarfy.width, 0.0f, (float)24, (float)scarfy.height/4 };
=======
    Vector2 origin = { (float)yotsuba.width/6, (float)yotsuba.height/8 };  // Set transform origin to sprite center
    Rectangle sourceRec = { 0.0f, 0.0f, (float)yotsuba.width/3, (float)yotsuba.height/4 };  // Section of spritesheet to draw
    Rectangle destRec = { 0.0f, 0.0f, 96.0f, 96.0f };  // Where to draw the sprite on screen. This allows changing the size

>>>>>>> f54f407f730a43893f37d09d56a7073716329d74
    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 8;            // Number of spritesheet frames shown by second

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
         // Update
        //----------------------------------------------------------------------------------
        framesCounter++;

	// Update sprite
        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

<<<<<<< HEAD
            if (currentFrame > 2) 
            {currentFrame = 0;
            frameRec.y+=scarfy.height/4;
            if (frameRec.y >scarfy.height/4*3)
            {
                frameRec.y = 0;
            }
            }

             	  	 
	currentFrame %= 3;
	frameRec.x = (float)currentFrame * (float)scarfy.width / 3;	  	 
=======
            if (currentFrame > 2) currentFrame = 0;

            sourceRec.x = (float)currentFrame*(float)yotsuba.width/3;
>>>>>>> f54f407f730a43893f37d09d56a7073716329d74
        }

	// Update position
	destRec.x = position.x;
	destRec.y = position.y;

        // Control frames speed
        if (IsKeyPressed(KEY_RIGHT)) framesSpeed++;
        else if (IsKeyPressed(KEY_LEFT)) framesSpeed--;

        if (framesSpeed > MAX_FRAME_SPEED) framesSpeed = MAX_FRAME_SPEED;
        else if (framesSpeed < MIN_FRAME_SPEED) framesSpeed = MIN_FRAME_SPEED;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

<<<<<<< HEAD
            DrawTexture(scarfy, 0, 40, WHITE);
            DrawRectangleLines(0, 40, scarfy.width, scarfy.height, LIME);
            DrawRectangleLines(6 + (int)frameRec.x, 40 + (int)frameRec.y, (int)frameRec.width, (int)frameRec.height, RED);
=======
            DrawTexture(yotsuba, 16, 40, WHITE);
            DrawRectangleLines(16, 40, yotsuba.width, yotsuba.height, LIME);
            DrawRectangleLines(16 + (int)sourceRec.x, 40 + (int)sourceRec.y, (int)sourceRec.width, (int)sourceRec.height, RED);
>>>>>>> f54f407f730a43893f37d09d56a7073716329d74

            DrawText("FRAME SPEED: ", 165, 210, 10, DARKGRAY);
            DrawText(TextFormat("%02i FPS", framesSpeed), 575, 210, 10, DARKGRAY);
            DrawText("PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 290, 240, 10, DARKGRAY);

            for (int i = 0; i < MAX_FRAME_SPEED; i++)
            {
                if (i < framesSpeed) DrawRectangle(250 + 21*i, 205, 20, 20, RED);
                DrawRectangleLines(250 + 21*i, 205, 20, 20, MAROON);
            }

            DrawTexturePro(yotsuba, sourceRec, destRec, origin, 0.0f, WHITE);

            DrawText("(c) Scarfy sprite by Eiden Marsal", screenWidth - 200, screenHeight - 20, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(yotsuba);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
