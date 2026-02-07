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

#endif