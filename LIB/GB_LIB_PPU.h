#ifndef INCLUDE_GB_LIB_PPU_H
#define INCLUDE_GB_LIB_PPU_H

typedef struct
{
    /* OG DMG color pallete */
    Color Zero;
    Color One;
    Color Two;
    Color Three; 
} PALLETE;

extern PALLETE DMG_Pallete;

const unsigned char SCREEN_SCANLINES = 144;
const unsigned char SCREEN_PIXELS_WIDE = 160;

unsigned short GetTileIdxFromVRAM(unsigned short, unsigned short);
unsigned char GetLSBTileRowOffset(unsigned short);
unsigned char GetPixelOffset(unsigned short);
unsigned char GetPixelValue(unsigned short, unsigned char, unsigned char, unsigned char);
void RunPPU();
unsigned char* GetScreenMemPtr();

#endif