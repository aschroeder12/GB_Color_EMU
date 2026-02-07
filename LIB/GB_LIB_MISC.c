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
