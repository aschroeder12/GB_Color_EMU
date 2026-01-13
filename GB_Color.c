#include "raylib.h"
#include "INSTR\GB_INSTR.c"
#include "MEM\MEMORY_MAP.c"
#include "MEM\GRAPHICS.c"
#include "GB_Lib.c"

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

void PrintStatus(void)
{
    PrintLog("PC_REGISTER = ");
    Print4HexLog(PC_REGISTER);
    PrintLog("SP_REGISTER = ");
    Print4HexLog(SP_REGISTER);
    PrintLog("ADDRESS_BUS = ");
    Print4HexLog(ADDRESS_BUS);
    PrintLog("A_REGISTER = ");
    Print2HexLog(A_REGISTER);
    PrintLog("B_REGISTER = ");
    Print2HexLog(B_REGISTER);
    PrintLog("C_REGISTER = ");
    Print2HexLog(C_REGISTER);
    PrintLog("D_REGISTER = ");
    Print2HexLog(D_REGISTER);
    PrintLog("E_REGISTER = ");
    Print2HexLog(E_REGISTER);
    PrintLog("F_REGISTER = ");
    Print2HexLog(F_REGISTER);
    PrintLog("H_REGISTER = ");
    Print2HexLog(H_REGISTER);
    PrintLog("L_REGISTER = ");
    Print2HexLog(L_REGISTER);
}

void FirstLoad(void)
{
    char a;
    int x = 0;
    FILE *fptr;
    fptr = fopen("../test_rom1.bin", "rb");
    
    if (fptr != NULL)
    {
        fread(BOOT_ROM, sizeof(unsigned char), 256, fptr);
    }
    else
    {
        printf("couldnt open file \n");
    }
    fclose(fptr);

    /* Init Memory */
    PC_REGISTER = 0x0000;
    BR_MODE = 1;
}


void LoadCartridge(void)
{
    char a;
    int x = 0;
    FILE *fptr;
    fptr = fopen("../test.gb", "rb");
    
    if (fptr != NULL)
    {
        fread(ROM_BANK_00, sizeof(unsigned char), 16384, fptr);
        fread(ROM_BANK_01, sizeof(unsigned char), 16384, fptr);
    }
    else
    {
        PrintLog("couldnt open gb file \n");
    }
    fclose(fptr);
}


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

    SetLogFile();
    FirstLoad();
    LoadCartridge();
    //WriteExampleVRAM();
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
        for (int i = 0; i < 32; i++)
        {
            DoGameBoyThings();
        }

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
    CloseLogFile();
    return 0;
}

