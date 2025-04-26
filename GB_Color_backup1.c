

/*******************************************************************************************
*
*   raylib [textures] example - Image loading and drawing on it
*
*   Example complexity rating: [★★☆☆] 2/4
*
*   NOTE: Images are loaded in CPU memory (RAM); textures are loaded in GPU memory (VRAM)
*
*   Example originally created with raylib 1.4, last time updated with raylib 1.4
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2016-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    unsigned char screenPixels[100*100*4] = {255};


    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image drawing");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    Image cat = LoadImage("cat.png");             // Load image in CPU memory (RAM)
    ImageCrop(&cat, (Rectangle){ 0, 10, 100, 100 });      // Crop an image piece
    ImageFormat(&cat, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    Texture2D texture = LoadTextureFromImage(cat);      // Image converted to texture, uploaded to GPU memory (VRAM)
    UnloadImage(cat);       // Unload image from RAM
    SetTargetFPS(60);
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        UpdateTexture(texture, &screenPixels);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, WHITE);
            DrawRectangleLines(screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, texture.width, texture.height, DARKGRAY);

            DrawText("We are drawing only one texture from various images composed!", 240, 350, 10, DARKGRAY);
            DrawText("Source images have been cropped, scaled, flipped and copied one over the other.", 190, 370, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

