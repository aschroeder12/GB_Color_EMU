#include "../MEM/GB_MEM.h"
#include "GB_LIB.h"

PALLETE DMG_Pallete;
unsigned char MEM_ScreenPixels[160*144*4] = {255};

/* GetTileIdxFromVRAM Function
 * Using x,y pixel coordinates, return the generic Tile Index (0-1023) 
 * that contains that pixel (because this function doesn't know the LCDC bits)
 */
unsigned short GetTileIdxFromVRAM(unsigned short x, unsigned short y)
{
	int tileIdx;
	/* Tile IDX = (y // 8)*32 + (x // 8) */
	tileIdx = ((y / (int)8)*((int)32)) + (x / (int)8);
	return (unsigned short)tileIdx;
}
/* GetLSBTileRowOffset Function
 * Using the y inputted value (0-255), find the correct LSB row of the tile (0-14)
 * that houses the pixel. Remember, MSB Row is LSB + 1 
 */
unsigned char GetLSBTileRowOffset(unsigned short y)
{
	return ((y % 8)* 2);
}
/* GetPixelOffset Function
 * This is pretty simple, using the inputted x value (0-255), find the correct 
 * column of the tile that corresponds to this pixel. This value will then be 
 * used to index into the row to get the LSB/MSB pallette value 
 */
unsigned char GetPixelOffset(unsigned short x)
{
	return (x % 8);
}

/* GetPixelValue Function
 * With the TileAddr, use TileRowLSB, TileRowMSB, and PixelOffset to get the correct
 * value for the 2 bit color value for this pixel. 
 */
unsigned char GetPixelValue(unsigned short tileAddr, unsigned char tileRowLSB, unsigned char tileRowMSB, unsigned char pixelOffset)
{
	unsigned char valueLSB;
	unsigned char valueMSB;
	valueLSB = ReadMemory(tileAddr + tileRowLSB);
	valueMSB = ReadMemory(tileAddr + tileRowMSB);
	/* Get the bit in valueLSB/MSB using PixelOffset */
	if (GB_isNthBitSet(valueMSB, pixelOffset)) /* 1x */
	{
		if (GB_isNthBitSet(valueLSB, pixelOffset)) /* 11 */
		{
			return (unsigned char)3;
		}
		else
		{
			return (unsigned char)2;
		}
	}
	else
	{
		if (GB_isNthBitSet(valueLSB, pixelOffset)) /* 01 */
		{
			return (unsigned char)1;
		}
		else
		{
			return (unsigned char)0;
		}
	}

}

void RunPPU(void)
{
	unsigned short startPixelX_Idx;
	unsigned short startPixelY_Idx;
	unsigned short currentPixelRow; /* 0-256 in Tile data*/
	unsigned short currentPixelCol; /* 0-256 in Tile data*/
	unsigned short tempTileMapAddr;
	unsigned char tempTileOffset;
	unsigned char tempTileRowLSB;
	unsigned char tempTileRowMSB;
	unsigned char tempTilePixelOffset;
	unsigned char pixelColorValue;
	unsigned long memScreenPixelIdx;

	//LCDC_REGISTER = ReadMemory(0xff40); /* LCDC Control Register */
	LCDC_REGISTER = 0x91;
	startPixelY_Idx = ReadMemory(0xFF42); /* SCY */
	startPixelX_Idx = ReadMemory(0xFF43); /* SCX */
	//PrintLog("startPixelY_Idx = ");
	//PrintShortDecLog(startPixelY_Idx);
	//PrintLog("startPixelX_Idx = ");
	//PrintShortDecLog(startPixelX_Idx);


	/* Run through Background Tile Map and write it to MemScreenPixels 
	 * You can repeatedly write to MemScreenPixels for the background/object/etc layers 
	 * before you finally write it out to the GPU at the end 
	 */
	if (GB_isNthBitSet(LCDC_REGISTER, 7))
	{
		for (int i = 0; i < SCREEN_SCANLINES; i++)
		{
			//currentPixelRow = (startPixelY_Idx + i) % 256;
			currentPixelRow = i;

			for (int j = 0; j < SCREEN_PIXELS_WIDE; j++)
			{
				
				//currentPixelCol = (startPixelX_Idx + j) % 256;
				currentPixelCol = j;
				/* Where to start depends on 3 things
				 * 1) Which Tile Map (LCDC bit 3)
				 * 2) Addressing method (LCDC bit 4)
				 * 3) SCY and SCX registers, specifying top-left coordinates of screen
				 * bottomPixel = (SCY + 143) % 256
				 * rightPixel = (SCX + 159) % 256
				 */

				if (GB_isNthBitSet(LCDC_REGISTER, 3)) /* (1) Tile Map 2 9C00 - 9FFF */
				{
					/* Add Tile Idx to Base Tile Memory Address to get the tile map Addr */
					tempTileMapAddr = 0x9c00 + GetTileIdxFromVRAM(currentPixelCol, currentPixelRow);
					/* Read that piece of memory to get the Tile VRAM offset 0-255 */
					tempTileOffset = ReadMemory(tempTileMapAddr);
					/* (1) unsigned addressing for the actual Tile Data. First half = 8000-87FF, Last Half = 8800-8FFF */
					if (GB_isNthBitSet(LCDC_REGISTER, 4)) 
					{
						/* Now that we have the tile, we need to get the rows in the tile */
						tempTileRowLSB = GetLSBTileRowOffset(currentPixelRow);
						tempTileRowMSB = tempTileRowLSB + 1;
						tempTilePixelOffset = GetPixelOffset(currentPixelCol);
						pixelColorValue = GetPixelValue(0x8000 + tempTileOffset, tempTileRowLSB, tempTileRowMSB, tempTilePixelOffset);

					}
					else /* (0) signed addressing for the actual Tile Data. First Half = 9000-97FF, Last Half 8800-8FFF */
					{
						PrintLog(" LCDC_REGISTER = ");
						Print2HexLog(LCDC_REGISTER);
						PrintLog("-SIGNED ADDRESSING AHHH! \n");
						/* Now that we have the tile, we need to get the rows in the tile */
						tempTileRowLSB = GetLSBTileRowOffset(currentPixelRow);
						tempTileRowMSB = tempTileRowLSB + 1;
						tempTilePixelOffset = GetPixelOffset(currentPixelCol);
						pixelColorValue = GetPixelValue(0x9000 + (signed char)tempTileOffset, tempTileRowLSB, tempTileRowMSB, tempTilePixelOffset);
					}
				}
				else /* (0) Tile Map 1 9800 - 9BFF */
				{
					tempTileMapAddr = 0x9800 + GetTileIdxFromVRAM(currentPixelCol, currentPixelRow);
					/* Read that piece of memory to get the Tile VRAM offset 0-255 */
					tempTileOffset = ReadMemory(tempTileMapAddr);
					/* (1) unsigned addressing for the actual Tile Data. First half = 8000-87FF, Last Half = 8800-8FFF */
					if (GB_isNthBitSet(LCDC_REGISTER, 4)) 
					{
						/* Now that we have the tile, we need to get the rows in the tile */
						tempTileRowLSB = GetLSBTileRowOffset(currentPixelRow);
						tempTileRowMSB = tempTileRowLSB + 1;
						tempTilePixelOffset = GetPixelOffset(currentPixelCol);
						pixelColorValue = GetPixelValue(0x8000 + tempTileOffset, tempTileRowLSB, tempTileRowMSB, tempTilePixelOffset);
						if (tempTileOffset != 0)
						{
							PrintLog("BEGIN--------------------------------\n");
							PrintLog ("i = ");
							PrintLongDecLog((long)i);
							PrintLog("   -   ");
							PrintLog ("j = ");
							PrintLongDecLog((long)j);
							PrintLog("\n");
							PrintLog("Tile Map Addr = ");
							Print4HexLog(tempTileMapAddr);
							PrintLog("   -   ");
							PrintLog("Tile Offset in VRAM = ");
							Print4HexLog(tempTileOffset);
							PrintLog("\n");
							PrintLog("Tile Row LSB  ");
							Print2HexLog(tempTileRowMSB);
							PrintLog("   -   ");
							PrintLog("Tile Row MSB = ");
							Print2HexLog(tempTileRowLSB);
							PrintLog("   -   ");
							PrintLog("Pixel Color Val = ");
							Print2HexLog(pixelColorValue);
							PrintLog("\n");
							//PrintVRAM();
						}
					}
					else
					{
						PrintLog("SIGNED ADDRESSING AHHH! \n");
						/* Now that we have the tile, we need to get the rows in the tile */
						tempTileRowLSB = GetLSBTileRowOffset(currentPixelRow);
						tempTileRowMSB = tempTileRowLSB + 1;
						tempTilePixelOffset = GetPixelOffset(currentPixelCol);
						pixelColorValue = GetPixelValue(0x9000 + (signed char)tempTileOffset, tempTileRowLSB, tempTileRowMSB, tempTilePixelOffset);
					}
					
				}
				/* Now that we have the Pixel Color Value (0 - 3), store it in the MEM_ScreenPixels array
				 */
				memScreenPixelIdx = (SCREEN_PIXELS_WIDE*4*i) + (4*j); 
				if (pixelColorValue == 3)
				{
					MEM_ScreenPixels[memScreenPixelIdx] = DMG_Pallete.Three.r;
	                MEM_ScreenPixels[memScreenPixelIdx + 1] = DMG_Pallete.Three.g;
	                MEM_ScreenPixels[memScreenPixelIdx + 2] = DMG_Pallete.Three.b;
	                MEM_ScreenPixels[memScreenPixelIdx + 3] = DMG_Pallete.Three.a;
				}
				else if (pixelColorValue == 2)
				{
					MEM_ScreenPixels[memScreenPixelIdx] = DMG_Pallete.Two.r;
	                MEM_ScreenPixels[memScreenPixelIdx + 1] = DMG_Pallete.Two.g;
	                MEM_ScreenPixels[memScreenPixelIdx + 2] = DMG_Pallete.Two.b;
	                MEM_ScreenPixels[memScreenPixelIdx + 3] = DMG_Pallete.Two.a;
				}
				else if (pixelColorValue == 1)
				{
					MEM_ScreenPixels[memScreenPixelIdx] = DMG_Pallete.One.r;
	                MEM_ScreenPixels[memScreenPixelIdx + 1] = DMG_Pallete.One.g;
	                MEM_ScreenPixels[memScreenPixelIdx + 2] = DMG_Pallete.One.b;
	                MEM_ScreenPixels[memScreenPixelIdx + 3] = DMG_Pallete.One.a;
				}
				else if (pixelColorValue == 0)
				{
					MEM_ScreenPixels[memScreenPixelIdx] = DMG_Pallete.Zero.r;
	                MEM_ScreenPixels[memScreenPixelIdx + 1] = DMG_Pallete.Zero.g;
	                MEM_ScreenPixels[memScreenPixelIdx + 2] = DMG_Pallete.Zero.b;
	                MEM_ScreenPixels[memScreenPixelIdx + 3] = DMG_Pallete.Zero.a;
				}
				else
				{
					PrintLog("ERROR: AAAAAAAAAAAAAAAAAAAAAA \n");
				}
				
			}
		}
	}
	else
	{
		PrintLog("LCDC_REGISTER bit 7 OFF, Screen OFF \n");
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
