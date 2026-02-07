#include "raylib.h"
#include "INSTR/GB_INSTR.c"
#include "LIB/GB_LIB.c"
#include "MEM/GB_MEM.c"

void DoGameBoyThings(void)
{
    /* PPU Timing 
     * Total Scan Lines - 154
     * Mode 0 - Horizantal Blank (everything accessible)
     * Mode 1 - Vertical Blank (everything accessible)
     * Mode 2 - OAM Scan (OAM inaccessible (except DMA))
     * Mode 3 - Drawing Pixels (VRAM, CGB palletes, OAM inaccessible (except DMA))
     * For Scan Lines 1 - 144
     * 80 dots (Mode 2) - 172-289 dots (Mode 3) - (376-Mode3) dots (Mode 0)
     * For Scan Lines 145 - 154
     * 456 dots (Mode 1)
     */

    unsigned short dotCnt;
    unsigned char lineCnt;
    unsigned char MaxLineCnt = 10;

    dotCnt = (unsigned short)0;
    lineCnt = (unsigned char)0;

    while (lineCnt < 144)
    {
        /* OAM Scan Begin */
        while (dotCnt < 80)
        {
            RunCPU(&dotCnt, (unsigned short)80);
        }
        /* OAM Scan End, Drawing Pixels Begin */
        while (dotCnt < 369)
        {
            /* 369 is the max, this most likely will exit before 369 */
            RunCPU(&dotCnt, (unsigned short)369);
        }
        /* Drawing Pixels End, Horizontal Blank Begin */
        while (dotCnt < 456)
        {
            RunCPU(&dotCnt, (unsigned short)456);
        }
        lineCnt = lineCnt + 1;
    }
    while (lineCnt < 154)
    {
        while (dotCnt < 456)
        {
            RunCPU(&dotCnt, (unsigned short)456);
        }
        lineCnt = lineCnt + 1;
    }
    PrintLog("CPU DONE, EXECUTE PPU \n");
    /* This isn't correct in the slightest, but for now just draw the screen after the CPU runs */
    RunPPU();
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int EmuWindowWidth = 512;
    const int EmuWindowHeight = 512;
    unsigned char* ScreenMEM;
    ClearMemory();
    SetLogFile();
    FirstLoad();
    LoadCartridge();
    //WriteExampleVRAM();
    InitWindow(EmuWindowWidth, EmuWindowHeight, "test example");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    Image cat = LoadImage("cat.png");             // Load image in CPU memory (RAM)
    ImageCrop(&cat, (Rectangle){ 0, 0, 160, 144 });      // Crop an image piece
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
        
        DoGameBoyThings();
        
        ScreenMEM = GetScreenMemPtr();
        UpdateTexture(texture, ScreenMEM);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, EmuWindowWidth/2 - texture.width/2, EmuWindowHeight/2 - texture.height/2 - 40, WHITE);
            DrawRectangleLines(EmuWindowWidth/2 - texture.width/2, EmuWindowHeight/2 - texture.height/2 - 40, texture.width, texture.height, DARKGRAY);

            DrawText("aschroeder12", 240, 350, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    CloseLogFile();
    return 0;
}

