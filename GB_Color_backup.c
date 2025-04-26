#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "GB_Registers.h"
#include"INSTR\GB_INSTR.h"
#include"MEM\GRAPHICS.c"
#include "MEM\MEMORY_MAP.c"
#include "raylib.h"

typedef struct PALLETE;

/* quick example to test printing to screen */
void WriteExampleVRAM()
{
    unsigned char dataArr[16] = {0xFF, 0x00, 0x7E, 0xFF, 0x85, 0x81, 0x89, 0x83, 0x93, 0x85, 0xA5, 0x8B, 0xC9, 0x97, 0x7E, 0xFF};
    unsigned short addr = 0x8000;
    for (int i = 0; i < 16; i++)
    {
        WriteMemory(addr + i, dataArr[i]);
    }
}



int main()
{
    printf("test 1\n");
    Image img = GenImageColor(12, 12, BLACK);
    printf("test 2\n");
    ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    printf("test 3\n");
    Texture tex = LoadTextureFromImage(img);
    printf("test 4\n");
    UnloadImage(img);

    PALLETE DMG_Pallete;
    /* OG DMG color pallete */
    DMG_Pallete.Zero = (Color){ 155, 188, 15, 255 } ;
    DMG_Pallete.One = (Color){ 139, 172, 15, 255 };
    DMG_Pallete.Two = (Color){ 48, 98, 48, 255 };
    DMG_Pallete.Three = (Color){ 15, 56, 15, 255 };
    
    //WriteExampleVRAM();
	
	// Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 256;
    const int screenHeight = 256;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            DrawTexture(tex, 0,0, WHITE);
            ClearBackground(RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    UnloadTexture(tex);

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

