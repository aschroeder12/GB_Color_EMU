#include<stdio.h>
#include "raylib.h"
#include "MEMORY_MAP.h"
typedef struct
{
    /* OG DMG color pallete */
    Color Zero;
    Color One;
    Color Two;
    Color Three; 
} PALLETE;

unsigned char MEM_ScreenPixels[256*256*4] = {255}; //262,144 Bytes


/*wooo stack overflow */
int GB_isNthBitSet (unsigned char c, int n) {
    static unsigned char mask[] = {128, 64, 32, 16, 8, 4, 2, 1};
    return ((c & mask[n]) != 0);
}

/* Function to Draw a Tile 
 * Deprecated, only used as a proof of concept */
void GB_DrawTile(unsigned short startMemAddr, unsigned char screenXPos, unsigned char screenYPos, int scaleFactor, PALLETE palleteParam)
{
    int i, j;
    unsigned char LSB_ROW;
    unsigned char MSB_ROW;

    /* Tiles are 8 x 8, i = row number, j = column number */
    for (i = screenYPos; i < screenYPos + (8*scaleFactor); i+= (1*scaleFactor))
    {
        /* For each new row, get the 2 bytes for the color pallete */
        LSB_ROW = ReadMemory(startMemAddr);
        startMemAddr = startMemAddr + 1;
        MSB_ROW = ReadMemory(startMemAddr);
        startMemAddr = startMemAddr + 1;
        for (int a = 0; a < scaleFactor; a++)
        {
            for (j = screenXPos; j < screenXPos + (8*scaleFactor); j+= (1*scaleFactor))
            {
                /* Use scaleFactor to scale the pixels width */
                if (GB_isNthBitSet(LSB_ROW, (int)(j-screenXPos)/scaleFactor) && GB_isNthBitSet(MSB_ROW, (int)(j-screenXPos)/scaleFactor))
                {
                    DrawLine(j,i+a,j+scaleFactor,i+a, palleteParam.Three );
                }
                else if (GB_isNthBitSet(MSB_ROW, (int)(j-screenXPos)/scaleFactor))
                {
                    DrawLine(j,i+a,j+scaleFactor,i+a, palleteParam.Two);
                }
                else if (GB_isNthBitSet(LSB_ROW, (int)(j-screenXPos)/scaleFactor))
                {
                    DrawLine(j,i+a,j+scaleFactor,i+a, palleteParam.One );
                }
                else
                {
                    DrawLine(j,i+a,j+scaleFactor,i+a, palleteParam.Zero);
                }
            }
        }
    }
}


void PrintScreenMEM()
{
    printf("Print Screen Mem \n");
    for (int i = 0; i < 64; i++)
    {
        printf("%x - ", MEM_ScreenPixels[i]);
    }
    printf("\n");
}


/* Update 1 Tile in the Screen Texture
 * Using the X and Y index, update the Screen with a new Tile, specified by the addr
 */
void GB_UpdateTextureTile(unsigned short tileMemAddrInVRAM, int textureXIndex, int textureYIndex, PALLETE palleteParam)
{
    int idx;
    unsigned char LSB_ROW;
    unsigned char MSB_ROW;
    /* convert VRAM format to texture format (1 byte for R, G, B, A) */
    idx = textureYIndex*(256*4) + (textureXIndex * 4);
    /* Tiles are 8 x 8, idx = pixel number, j = column number */
    for (int j = 0; j < 8; j++)
    {
        /* Get the 2 bytes for the color pallete */
        LSB_ROW = ReadMemory(tileMemAddrInVRAM);
        tileMemAddrInVRAM = tileMemAddrInVRAM + 1;
        MSB_ROW = ReadMemory(tileMemAddrInVRAM);
        tileMemAddrInVRAM = tileMemAddrInVRAM + 1;
        for (int j = 0; j < 8; j+= 1)
        {
            /* Update the MEM_ScreenPixels at XIndex, YIndex */
            if (GB_isNthBitSet(LSB_ROW, j) && GB_isNthBitSet(MSB_ROW, j))
            {
                /* r, g, b, a */
                MEM_ScreenPixels[idx] = palleteParam.Three.r;
                MEM_ScreenPixels[idx + 1] = palleteParam.Three.g;
                MEM_ScreenPixels[idx + 2] = palleteParam.Three.b;
                MEM_ScreenPixels[idx + 3] = palleteParam.Three.a;
            }
            else if (GB_isNthBitSet(MSB_ROW, j))
            {
                /* r, g, b, a */
                MEM_ScreenPixels[idx] = palleteParam.Two.r;
                MEM_ScreenPixels[idx + 1] = palleteParam.Two.g;
                MEM_ScreenPixels[idx + 2] = palleteParam.Two.b;
                MEM_ScreenPixels[idx + 3] = palleteParam.Two.a;
            }
            else if (GB_isNthBitSet(LSB_ROW, j))
            {
                /* r, g, b, a */
                MEM_ScreenPixels[idx] = palleteParam.One.r;
                MEM_ScreenPixels[idx + 1] = palleteParam.One.g;
                MEM_ScreenPixels[idx + 2] = palleteParam.One.b;
                MEM_ScreenPixels[idx + 3] = palleteParam.One.a;
            }
            else
            {
                /* r, g, b, a */
                MEM_ScreenPixels[idx] = palleteParam.Zero.r;
                MEM_ScreenPixels[idx + 1] = palleteParam.Zero.g;
                MEM_ScreenPixels[idx + 2] = palleteParam.Zero.b;
                MEM_ScreenPixels[idx + 3] = palleteParam.Zero.a;
            }
            idx = idx + 4;
        }
        idx = idx + (256*4)-(32) ; /* jump to beginning of next row */
    }
}

/* Getter for the Screen Memory 
 * Lets us do all our texture updates, and then return the 
 * pointer at the end 
 */
unsigned char* GetScreenMemPtr(void)
{
    return &MEM_ScreenPixels[0];
}

