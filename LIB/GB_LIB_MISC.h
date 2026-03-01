#ifndef INCLUDE_GB_LIB_MISC_H
#define INCLUDE_GB_LIB_MISC_H

void SetLogFile();
void CloseLogFile();
void PrintLog(char *);
void Print4HexLog(unsigned short);
void Print2HexLog(unsigned char);
void PrintLongDecLog(unsigned long);
void PrintShortDecLog(unsigned short);
int GB_isNthBitSet (unsigned char, int);
void WriteExampleVRAM();
void PrintVRAM();
void PrintTileMap();
void PrintStatus();
void FirstLoad();
void LoadCartridge();
unsigned char HalfCarrySetAdd_8(unsigned char, unsigned char);
unsigned char HalfCarrySetSub_8(unsigned char, unsigned char);
unsigned char HalfCarrySetAdd_16(unsigned short, unsigned short);
unsigned char HalfCarrySetSub_16(unsigned short, unsigned short);
unsigned char CarrySetAdd_8(unsigned char, unsigned char);
unsigned char CarrySetSub_8(unsigned char, unsigned char);
unsigned char CarrySetAdd_16(unsigned short, unsigned short);
unsigned char CarrySetSub_16(unsigned short, unsigned short);

#endif