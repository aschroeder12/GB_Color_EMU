#ifndef INCLUDE_MEMORY_MAP_H
#define INCLUDE_MEMORY_MAP_H

unsigned char ReadMemory(unsigned short);
void WriteMemory(unsigned short, unsigned char );
void ClearMemory();

extern unsigned char BOOT_ROM[256];

extern unsigned char ROM_BANK_00[16384];
extern unsigned char ROM_BANK_01[16384];
extern unsigned char VRAM[8192];
extern unsigned char EXTERNAL_RAM[8192];
extern unsigned char WRAM_1[4096];
extern unsigned char WRAM_2[4096];
extern unsigned char OAM[160];
extern unsigned char IO_REGISTERS[128];
extern unsigned char HRAM[127];
extern unsigned char IE_REGISTER;

#endif