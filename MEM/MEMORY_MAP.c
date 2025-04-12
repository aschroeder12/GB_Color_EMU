/* GB MEMORY MAP
 * 0000	3FFF	16 KiB ROM bank 00	From cartridge, usually a fixed bank
 * 4000	7FFF	16 KiB ROM Bank 01–NN	From cartridge, switchable bank via mapper (if any)
 * 8000	9FFF	8 KiB Video RAM (VRAM)	In CGB mode, switchable bank 0/1
 * A000	BFFF	8 KiB External RAM	From cartridge, switchable bank if any
 * C000	CFFF	4 KiB Work RAM (WRAM)	
 * D000	DFFF	4 KiB Work RAM (WRAM)	In CGB mode, switchable bank 1–7
 * E000	FDFF	Echo RAM (mirror of C000–DDFF)	Nintendo says use of this area is prohibited.
 * FE00	FE9F	Object attribute memory (OAM)	
 * FEA0	FEFF	Not Usable	Nintendo says use of this area is prohibited.
 * FF00	FF7F	I/O Registers	
 * FF80	FFFE	High RAM (HRAM)	
 * FFFF	FFFF	Interrupt Enable register (IE)	
 */
#include<math.h> /* pow */

/* Gonna go with the easy solution, use an array of "bits" (chars) 
 * I could do a 1-to-1 memory arrays and do bit shifting, but I don't know if all Memory operations are Byte aligned?
 * If they are, it'd be easy. If they aren't, then it would suck big time
 */

unsigned char ROM_BANK_00[16384];
/* unsigned char ROM_BANK_01[16384]; Not on GB? */
unsigned char VRAM[8192];
unsigned char EXTERNAL_RAM[8192];
unsigned char WRAM_1[4096];
unsigned char WRAM_2[4096];
unsigned char OAM[160];
unsigned char IO_REGISTERS[128];
unsigned char HRAM[127];
unsigned char IE_REGISTER;

unsigned char ConvertFromBitsToDecimal(unsigned char* beginAddr, unsigned char size)
{
	unsigned char result;
	unsigned char value; 

	for (unsigned char i = 0; i < size; i++)
	{
		value = *beginAddr;
		result = result + (value)*(pow(2,(size - (i + 1))));
		beginAddr++;
	}
	return result;
}

unsigned char ReadMemory(unsigned short addr)
{
	unsigned char * ptr;
	unsigned char result;
	/* Bank 00 */
	if (addr <= (unsigned short)0x3fff)
	{
		/* convert addr to index in ROM_BANK_00, and get its address */
		ptr = &ROM_BANK_00[add - 0];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* BANK 01, only on GB Color? */
	else if (addr <= (unsigned short)0x7fff)
	{
		/*  what do */
	}
	/* VRAM */
	else if (addr <= (unsigned short)0x9fff)
	{
		/* convert addr to index in VRAM, and get its address */
		ptr = &VRAM[add - (unsigned char)0x8000];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* EXTERNAL RAM */
	else if (addr <= (unsigned short)0xbfff)
	{
		/* convert addr to index in EXTERNAL RAM, and get its address */
		ptr = &EXTERNAL_RAM[add - (unsigned char)0xa000];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* WRAM_1 */
	else if (addr <= (unsigned short)0xcfff)
	{
		/* convert addr to index in WRAM_1, and get its address */
		ptr = &WRAM_1[add - (unsigned char)0xc000];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* WRAM_2 */
	else if (addr <= (unsigned short)0xdfff)
	{
		/* convert addr to index in WRAM_2, and get its address */
		ptr = &WRAM_2[add - (unsigned char)0xd000];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* ECHO_RAM */
	else if (addr <= (unsigned short)0xfdff)
	{
		/* Prohibado, I said it in Spanish, how much cleared could I have been? */
	}
	/* OAM */
	else if (addr <= (unsigned short)0xfe9f)
	{
		/* convert addr to index in OAM, and get its address */
		ptr = &OAM[add - (unsigned char)0xfe00];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* No */
	else if (addr <= (unsigned short)0xfeff)
	{
	
	}
	/* IO REGISTERS */
	else if (addr <= (unsigned short)0xff7f)
	{
		/* convert addr to index in IO_REGISTERS, and get its address */
		ptr = &IO_REGISTERS[add - (unsigned char)0xff00];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* HIGH RAM */
	else if (addr <= (unsigned short)0xfffe)
	{
		/* convert addr to index in HRAM, and get its address */
		ptr = &HRAM[add - (unsigned char)0xff80];
		result = ConvertFromBitsToDecimal(ptr, 8);
	}
	/* IE REGISTER */
	else if (addr <= (unsigned short)0xffff)
	{
		/* convert addr to index in HRAM, and get its address */
		ptr = &IE_REGISTER;
		result = ConvertFromBitsToDecimal(ptr, 1);
	}
	else
	{
		/* wut */
	}

	return result;
}