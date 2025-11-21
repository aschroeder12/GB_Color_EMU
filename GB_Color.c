#include "raylib.h"

#include "MEM\MEMORY_MAP.c"
#include "MEM\GRAPHICS.c"

typedef struct PALLETE;

/* quick example to test printing to screen */
void WriteExampleVRAM(void)
{
    unsigned char dataArr[16] = {0xFF, 0x00, 0x7E, 0xFF, 0x85, 0x81, 0x89, 0x83, 0x93, 0x85, 0xA5, 0x8B, 0xC9, 0x97, 0x7E, 0xFF};
    unsigned short addr = 0x8000;
    for (int i = 0; i < 16; i++)
    {
        WriteMemory(addr + i, dataArr[i]);
    }
    /* Write a bright tile for debugging */
    addr = 0x8010;
    for (int i = 0; i < 16; i++)
    {
        WriteMemory(addr + i, 0x00);
    }
}
/*
void LoadCatridge(char* fileName)
{
    FILE* fptr;
    fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        printf("Catridge not found with that file name \n");
    }
    // check for cartridge size??? 0x0148, but worry about this later
    // check for any cartridge RAM, do this later
    else
    {

    }
    fclose(fptr);
}
*/
void DoGameBoyThings(void)
{

}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 512;
    const int screenHeight = 512;
    unsigned short tileAddr = 0x8000;
    unsigned char* ScreenMEM;
    int i, j, cnt;

    PALLETE DMG_Pallete;
    /* OG DMG color pallete */
    DMG_Pallete.Zero = (Color){ 155, 188, 15, 255 } ;
    DMG_Pallete.One = (Color){ 139, 172, 15, 255 };
    DMG_Pallete.Two = (Color){ 48, 98, 48, 255 };
    DMG_Pallete.Three = (Color){ 15, 56, 15, 255 };

    //LoadCatridge("C:/Users/andre/Documents/ProgrammingProjects/Github/GB_Color/test_rom.bin");

    WriteExampleVRAM();
    InitWindow(screenWidth, screenHeight, "test example");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    Image cat = LoadImage("cat.png");             // Load image in CPU memory (RAM)
    ImageCrop(&cat, (Rectangle){ 0, 0, 256, 256 });      // Crop an image piece
    ImageFormat(&cat, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    Texture2D texture = LoadTextureFromImage(cat);      // Image converted to texture, uploaded to GPU memory (VRAM)
    UnloadImage(cat);       // Unload image from RAM
    SetTargetFPS(60);
    cnt = -1;
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        DoGameBoyThings();

        cnt = cnt + 1;
        if (cnt > 512)
        {
            cnt = 0;
        }
        for (i = 0; i < 256; i += 8)
        {
            for (j = 0; j < 256; j += 8)
            {
                if (i + j != cnt)
                {
                    GB_UpdateTextureTile(tileAddr, i,j, DMG_Pallete);
                }
                else
                {
                    GB_UpdateTextureTile(0x8010, i, j, DMG_Pallete);
                }
            }
        }
        ScreenMEM = GetScreenMemPtr();
        UpdateTexture(texture, ScreenMEM);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, WHITE);
            DrawRectangleLines(screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 40, texture.width, texture.height, DARKGRAY);

            DrawText("Testing out modifying a texture", 240, 350, 10, DARKGRAY);

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

