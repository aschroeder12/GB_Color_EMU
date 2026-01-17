#include"GB_Registers.h"
#include"GB_Buses.c"
#include"GB_Registers.c"

extern int GB_isNthBitSet (unsigned char, int );
extern unsigned char MEM_ScreenPixels[160*144*4]; 

FILE* LOGFILE;

typedef struct
{
    /* OG DMG color pallete */
    Color Zero;
    Color One;
    Color Two;
    Color Three; 
} PALLETE;

const unsigned char SCREEN_SCANLINES = 144;
const unsigned char SCREEN_PIXELS_WIDE = 160;
PALLETE DMG_Pallete;

void PrintStatus();
void PrintLog(char *);
void Print4HexLog(unsigned short);
void Print2HexLog(unsigned char);
void PrintLongDecLog(unsigned long);
void PrintShortDecLog(unsigned short);
void PrintTileMap();

void SetLogFile(void)
{
	LOGFILE = fopen("LOGS/TestLog.txt","a");
}
void CloseLogFile(void)
{
	fclose(LOGFILE);
}

void RunCPU(unsigned short *beginDotCnt, unsigned short endDotCnt)
{
	unsigned short tmp;
	unsigned short tmp2;
	if (PC_REGISTER == 0x0040)
	{
		PrintTileMap();
	}
	tmp = ReadMemory(PC_REGISTER);
	PrintLog("Current INSTR (see line below for name) = ");
	Print4HexLog(tmp);
	/* TEMP FOR TESTING, NEED TO FIX */
	*beginDotCnt = *beginDotCnt + 3;

	switch(tmp)
	{
	case 0x04:
		PrintLog("INC B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_R(&B_REGISTER);
		break;
	case 0x05:
		PrintLog("DEC B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&B_REGISTER);
		break;
	case 0x06:
		PrintLog("LD B n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&B_REGISTER);
		break;
	case 0x0d:
		PrintLog("DEC C \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&C_REGISTER);
		break;
	case 0x0c:
		PrintLog("INC C \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_R(&C_REGISTER);
		break;
	case 0x0e:
		PrintLog("LD C n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&C_REGISTER);
		break;
	case 0x11:
		PrintLog("LD DE nn Debug this \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_RR_NN(&D_REGISTER, &E_REGISTER);
		break;
	case 0x13:
		PrintLog("INC DE debug this\n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_RR(&D_REGISTER, &E_REGISTER);
		break;
	case 0x15:
		PrintLog("DEC D \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&D_REGISTER);
		break;
	case 0x16:
		PrintLog("LD D n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&D_REGISTER);
		break;
	case 0x17:
		PrintLog("RLA \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_RLA(&A_REGISTER);
		break;
	case 0x18:
		PrintLog("JR e \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR();
		break;
	case 0x1a:
		PrintLog("LD A DE \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_A_DE();
		break;
	case 0x1d:
		PrintLog("DEC E \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&E_REGISTER);
		break;
	case 0x1e:
		PrintLog("LD E n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&E_REGISTER);
		break;
	case 0x20:
		PrintLog("JR NZ \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR_NZ();
		break;
	case 0x21:
		PrintLog("LD HL nn \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_RR_NN(&H_REGISTER, &L_REGISTER);
		break;
	case 0x22:
		PrintLog("LD HL+ A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_HLI_A();
		break;
	case 0x23:
		PrintLog("INC HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_RR(&H_REGISTER, &L_REGISTER);
		break;
	case 0x24:
		PrintLog("INC H \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_INC_R(&H_REGISTER);
		break;
	case 0x28:
		PrintLog("JR Z e \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_JUMPR_Z();
		break;
	case 0x2e:
		PrintLog("LD L n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&L_REGISTER);
		break;
	case 0x31:
		PrintLog("LD SP \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_SP_NN();
		break;
	case 0x32:
		PrintLog("LD HL - A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_HLD_A();
		break;
	case 0x3d:
		PrintLog("DEC A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_DEC_R(&A_REGISTER);
		break;
	case 0x3e:
		PrintLog("LD A n \n"); //0011
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_N(&A_REGISTER);
		break;
	case 0x4f:
		PrintLog("LD C A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&C_REGISTER, &A_REGISTER);
		break;
	case 0x57:
		PrintLog("LD D A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&D_REGISTER, &A_REGISTER);
		break;
	case 0x67:
		PrintLog("LD H A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&H_REGISTER, &A_REGISTER);
		break;
	case 0x77:
		PrintLog("LD HL A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_HL_R(&A_REGISTER);
		break;
	case 0x78:
		PrintLog("LD A B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &B_REGISTER);
		break;
	case 0x7b:
		PrintLog("LD A E \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &E_REGISTER);
		break;
	case 0x7c:
		PrintLog("LD A H \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &H_REGISTER);
		break;
	case 0x7d:
		PrintLog("LD A L \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_REGISTER_R_r(&A_REGISTER, &L_REGISTER);
		break;
	case 0x86:
		PrintLog("ADD HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_ADD_REGISTER_HL();
		break;
	case 0x90:
		PrintLog("SUB B \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_SUB_REGISTER_R(&B_REGISTER);
		break;
	case 0xaf:
		PrintLog("XOR A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_XOR_REGISTER_R(&A_REGISTER);
		break;
	case 0xbe:
		PrintLog("CP HL \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CP_REGISTER_HL();
		break;
	case 0xc1:
		PrintLog("POP BC \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_POP_RR(&B_REGISTER, &C_REGISTER);
		break;
	case 0xc5:
		PrintLog("PUSH BC \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_PUSH_RR(&B_REGISTER, &C_REGISTER);
		break;
	case 0xc9:
		PrintLog("RET \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_RETURN();
		break;
	case 0xcb:
		PrintLog("CB PREFIXED - ");
		PC_REGISTER = PC_REGISTER + 1;
		tmp2 = ReadMemory(PC_REGISTER);
		switch(tmp2)
		{
		case 0x11:
			PrintLog("RL C \n");
			PC_REGISTER = PC_REGISTER + 1;
			INSTR_RL_REGISTER_R(&C_REGISTER);
			break;
		case 0x7c:
			PrintLog("BIT 7 H \n");
			PC_REGISTER = PC_REGISTER + 1;
			INSTR_BIT_REGISTER_R((unsigned char)7, &H_REGISTER);
			break;
		default:
			break;
		}
		break;
	case 0xcd:
		PrintLog("CALL n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CALL();
		break;
	case 0xe0:
		PrintLog("LDH n A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_N_A();
		break;
	case 0xe2:
		PrintLog("LDH C A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_C_A();
		break;
	case 0xea:
		PrintLog("LDH nn A \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_NN_A();
		break;
	case 0xf0:
		PrintLog("LDH A n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_LOAD_HW_A_N();
		break;
	case 0xfe:
		PrintLog("CP n \n");
		PC_REGISTER = PC_REGISTER + 1;
		INSTR_CP_N();
		break;
	default:
		PrintLog("Undefined instruction \n");
		PC_REGISTER = PC_REGISTER + 1;
		break;
	}
	PrintStatus();
}

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

	startPixelY_Idx = ReadMemory(0xFF42); /* SCY */
	startPixelX_Idx = ReadMemory(0xFF43); /* SCX */
	PrintLog("startPixelY_Idx = ");
	PrintShortDecLog(startPixelY_Idx);
	PrintLog("startPixelX_Idx = ");
	PrintShortDecLog(startPixelX_Idx);


	/* Run through Background Tile Map and write it to MemScreenPixels 
	 * You can repeatedly write to MemScreenPixels for the background/object/etc layers 
	 * before you finally write it out to the GPU at the end 
	 */
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

			if (GB_isNthBitSet(*LCDC_REGISTER, 3)) /* (1) Tile Map 2 9C00 - 9FFF */
			{
				/* Add Tile Idx to Base Tile Memory Address to get the tile map Addr */
				tempTileMapAddr = 0x9c00 + GetTileIdxFromVRAM(currentPixelCol, currentPixelRow);
				/* Read that piece of memory to get the Tile VRAM offset 0-255 */
				tempTileOffset = ReadMemory(tempTileMapAddr);
				/* (1) unsigned addressing for the actual Tile Data. First half = 8000-87FF, Last Half = 8800-8FFF */
				if (GB_isNthBitSet(*LCDC_REGISTER, 4)) 
				{
					/* Now that we have the tile, we need to get the rows in the tile */
					tempTileRowLSB = GetLSBTileRowOffset(currentPixelRow);
					tempTileRowMSB = tempTileRowLSB + 1;
					tempTilePixelOffset = GetPixelOffset(currentPixelCol);
					pixelColorValue = GetPixelValue(0x8000 + tempTileOffset, tempTileRowLSB, tempTileRowMSB, tempTilePixelOffset);

				}
				else /* (0) signed addressing for the actual Tile Data. First Half = 9000-97FF, Last Half 8800-8FFF */
				{

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
				//if (GB_isNthBitSet(*LCDC_REGISTER, 4)) 
				//{

					/* Now that we have the tile, we need to get the rows in the tile */
					tempTileRowLSB = GetLSBTileRowOffset(currentPixelRow);
					tempTileRowMSB = tempTileRowLSB + 1;
					tempTilePixelOffset = GetPixelOffset(currentPixelCol);
					pixelColorValue = GetPixelValue(0x8000 + tempTileOffset, tempTileRowLSB, tempTileRowMSB, tempTilePixelOffset);
				//}
				//else /* (0) signed addressing for the actual tile data. First Half = 9000-97FF, Last Half 8800-8FFF */
				//{
				//	PrintLog("LDCD Register = ");
				//	Print2HexLog(*LCDC_REGISTER);
					/* Now that we have the tile, we need to get the rows in the tile */
				//	tempTileRowLSB = GetLSBTileRowOffset(currentPixelRow);
				//	tempTileRowMSB = tempTileRowLSB + 1;
				//	tempTilePixelOffset = GetPixelOffset(currentPixelCol);
				//	pixelColorValue = GetPixelValue(0x9000 + (signed char)tempTileOffset, tempTileRowLSB, tempTileRowMSB, tempTilePixelOffset);
				//}
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


void PrintLog(char * logStr)
{
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, logStr);
	}
}

void Print4HexLog(unsigned short val)
{
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, "%04x \n", val);
	}
}
void Print2HexLog(unsigned char val)
{
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, "%02x \n", val);
	}
}
void PrintLongDecLog(unsigned long val)
{
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, "%d \n", val);
	}
}
void PrintShortDecLog(unsigned short val)
{
	if (LOGFILE == NULL)
	{
		printf("Could not open file \n");
	}
	else
	{
		fprintf(LOGFILE, "%d \n", val);
	}
}
