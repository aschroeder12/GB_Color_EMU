#include "stdio.h"
#include "../MEM/GB_MEM.h"
#include "GB_LIB_MISC.h"

FILE* LOGFILE;

void SetLogFile(void)
{
	LOGFILE = fopen("LOGS/TestLog.txt","a");
}
void CloseLogFile(void)
{
	fclose(LOGFILE);
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
		fprintf(LOGFILE, "%04x", val);
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
		fprintf(LOGFILE, "%02x", val);
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
		fprintf(LOGFILE, "%lu", val);
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
		fprintf(LOGFILE, "%d", val);
	}
}

int GB_isNthBitSet (unsigned char c, int n) {
    static unsigned char mask[] = {1, 2, 4, 8, 16, 32, 64, 128};
    return ((c & mask[n]) != 0);
}

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

void PrintVRAM(void)
{
    unsigned short addr = 0x8000;
    for (addr; addr < 0x9820; addr++)
    {
        PrintLog("VRAM addr = ");
        Print4HexLog(addr);
        PrintLog("   -   ");
        PrintLog("VRAM value = ");
        Print2HexLog(ReadMemory(addr));
        PrintLog("\n");
    }
}

void PrintTileMap(void)
{
    PrintLog("Print Tile map \n");
    unsigned short addr = 0x9800;
    for (addr; addr < 0x9C00; addr++)
    {
        if (ReadMemory(addr))
        {
            PrintLog("TileMapAddr = ");
            Print4HexLog(addr);
            PrintLog("   -   ");
            PrintLog("TileMapIndex val = ");
            Print2HexLog(ReadMemory(addr));
            PrintLog("\n");
        }
    }
}

void PrintStatus(void)
{
    PrintLog("PC_REGISTER = ");
    Print4HexLog(PC_REGISTER);
    PrintLog ("   -   ");
    PrintLog("SP_REGISTER = ");
    Print4HexLog(SP_REGISTER);
    PrintLog ("   -   ");
    PrintLog("ADDRESS_BUS = ");
    Print4HexLog(ADDRESS_BUS);
    PrintLog("\n");
    PrintLog("A_REGISTER = ");
    Print2HexLog(A_REGISTER);
    PrintLog ("   -   ");
    PrintLog("B_REGISTER = ");
    Print2HexLog(B_REGISTER);
    PrintLog ("   -   ");
    PrintLog("C_REGISTER = ");
    Print2HexLog(C_REGISTER);
    PrintLog ("   -   ");
    PrintLog("D_REGISTER = ");
    Print2HexLog(D_REGISTER);
    PrintLog("\n");
    PrintLog("E_REGISTER = ");
    Print2HexLog(E_REGISTER);
    PrintLog ("   -   ");
    PrintLog("F_REGISTER = ");
    Print2HexLog(F_REGISTER);
    PrintLog ("   -   ");
    PrintLog("H_REGISTER = ");
    Print2HexLog(H_REGISTER);
    PrintLog ("   -   ");
    PrintLog("L_REGISTER = ");
    Print2HexLog(L_REGISTER);
    PrintLog("\n");
    PrintLog("LCDC_REGISTER = ");
    Print2HexLog(LCDC_REGISTER);
    PrintLog("\n");
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
    DMG_Pallete.Zero = (Color){ 155, 188, 15, 255 } ;
    DMG_Pallete.One = (Color){ 139, 172, 15, 255 };
    DMG_Pallete.Two = (Color){ 48, 98, 48, 255 };
    DMG_Pallete.Three = (Color){ 15, 56, 15, 255 };

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

/* Function HalfCarrySetAdd_8
 * Function to determine whether a half-carry occured during an addition
 * This happens when a bit goes from bit 3 -> 4
 * returns 1 if half-carry, 0 otherwise
 */
unsigned char HalfCarrySetAdd_8(unsigned char a, unsigned char b)
{
    unsigned short x,y;
    unsigned short result;
    x = a;
    y = b;
    result = ((x & 0xf) + (y & 0xf)) & 0x10;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function HalfCarrySetSub_8
 * Function to determine whether a half-carry occured during a subtraction
 * This happens when a bit goes from bit 3 -> 4
 * returns 1 if half-carry, 0 otherwise
 */
unsigned char HalfCarrySetSub_8(unsigned char a, unsigned char b)
{
    unsigned short x,y;
    unsigned short result;
    x = a;
    y = b;
    result = ((x & 0xf) - (y & 0xf)) & 0x10;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function HalfCarrySetAdd_16
 * Function to determine whether a half-carry occured during an addition
 * This happens when a bit goes from bit 11 -> 12???
 * returns 1 if half-carry, 0 otherwise
 */
unsigned char HalfCarrySetAdd_16(unsigned short a, unsigned short b)
{
    unsigned int x,y;
    unsigned int result;
    x = a;
    y = b;
    result = ((x & 0xfff) + (y & 0xfff)) & 0x1000;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function HalfCarrySetSub_16
 * Function to determine whether a half-carry occured during a subtraction
 * This happens when a bit goes from bit 11 -> 12???
 * returns 1 if half-carry, 0 otherwise
 */
unsigned char HalfCarrySetSub_16(unsigned short a, unsigned short b)
{
    unsigned int x,y;
    unsigned int result;
    x = a;
    y = b;
    result = ((x & 0xfff) - (y & 0xfff)) & 0x1000;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function CarrySetAdd_8
 * Function to determine whether a Carry occured during an addition
 * This happens when a bit goes from bit 7 -> 8
 * returns 1 if carry, 0 otherwise
 */
unsigned char CarrySetAdd_8(unsigned char a, unsigned char b)
{
    unsigned short x,y;
    unsigned short result;
    x = a;
    y = b;
    result = ((x & 0xff) + (y & 0xff)) & 0x100;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function CarrySetSub_8
 * Function to determine whether a carry occured during a subtraction
 * This happens when a bit goes from bit 7 -> 8
 * returns 1 if carry, 0 otherwise
 */
unsigned char CarrySetSub_8(unsigned char a, unsigned char b)
{
    unsigned short x,y;
    unsigned short result;
    x = a;
    y = b;
    result = ((x & 0xff) - (y & 0xff)) & 0x100;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function CarrySetAdd_16
 * Function to determine whether a carry occured during an addition
 * This happens when a bit goes from bit 15 -> 16
 * returns 1 if carry, 0 otherwise
 */
unsigned char HalfCarrySetAdd_16(unsigned short a, unsigned short b)
{
    unsigned int x,y;
    unsigned int result;
    x = a;
    y = b;
    result = ((x & 0xffff) + (y & 0xffff)) & 0x10000;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function CarrySetSub_16
 * Function to determine whether a carry occured during a subtraction
 * This happens when a bit goes from bit 15 -> 16
 * returns 1 if carry, 0 otherwise
 */
unsigned char CarrySetSub_16(unsigned short a, unsigned short b)
{
    unsigned int x,y;
    unsigned int result;
    x = a;
    y = b;
    result = ((x & 0xffff) - (y & 0xffff)) & 0x10000;
    if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


