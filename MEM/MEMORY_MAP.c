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

/* Gonna go with the easy solution, use an array of bytes (chars) 
 */

unsigned char ROM_BANK_00[16384];
unsigned char ROM_BANK_01[16384];
unsigned char VRAM[8192];
unsigned char EXTERNAL_RAM[8192];
unsigned char WRAM_1[4096];
unsigned char WRAM_2[4096];
unsigned char OAM[160];
unsigned char IO_REGISTERS[128];
unsigned char HRAM[127];
unsigned char IE_REGISTER;


/* ReadMemory Function
 * Based on address, access correct memory region and return the 8 bit data
 */
unsigned char ReadMemory(unsigned short addr)
{
	unsigned char result;
	/* Bank 00 */
	if (addr <= (unsigned short)0x3fff)
	{
		/* convert addr to index in ROM_BANK_00, and get its address */
		result = ROM_BANK_00[addr - 0];
	}
	/* BANK 01 */
	else if (addr <= (unsigned short)0x7fff)
	{
		/* convert addr to index in ROM_BANK_01, and get its address */
		result = ROM_BANK_01[addr - (unsigned char)0x4000];
	}
	/* VRAM */
	else if (addr <= (unsigned short)0x9fff)
	{
		/* convert addr to index in VRAM, and get its address */
		result = VRAM[addr - (unsigned char)0x8000];
	}
	/* EXTERNAL RAM */
	else if (addr <= (unsigned short)0xbfff)
	{
		/* convert addr to index in EXTERNAL RAM, and get its address */
		result = EXTERNAL_RAM[addr - (unsigned char)0xa000];
	}
	/* WRAM_1 */
	else if (addr <= (unsigned short)0xcfff)
	{
		/* convert addr to index in WRAM_1, and get its address */
		result = WRAM_1[addr - (unsigned char)0xc000];
	}
	/* WRAM_2 */
	else if (addr <= (unsigned short)0xdfff)
	{
		/* convert addr to index in WRAM_2, and get its address */
		result = WRAM_2[addr - (unsigned char)0xd000];
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
		result = OAM[addr - (unsigned char)0xfe00];
	}
	/* No */
	else if (addr <= (unsigned short)0xfeff)
	{
	
	}
	/* IO REGISTERS */
	else if (addr <= (unsigned short)0xff7f)
	{
		/* convert addr to index in IO_REGISTERS, and get its address */
		result = IO_REGISTERS[addr - (unsigned char)0xff00];
	}
	/* HIGH RAM */
	else if (addr <= (unsigned short)0xfffe)
	{
		/* convert addr to index in HRAM, and get its address */
		result = HRAM[addr - (unsigned char)0xff80];
	}
	/* IE REGISTER */
	else if (addr <= (unsigned short)0xffff)
	{
		/* convert addr to index in HRAM, and get its address */
		result = IE_REGISTER;
	}
	else
	{
		/* wut */
	}

	return result;
}

/* Write Memory Function
 * Based on the address, write the data to the correct memory location
 */
void WriteMemory(unsigned short addr, unsigned char data)
{
	/* Bank 00 */
	if (addr <= (unsigned short)0x3fff)
	{
		/* Write data to the adjusted index */
		ROM_BANK_00[addr - 0] = data;
	}
	/* BANK 01 */
	else if (addr <= (unsigned short)0x7fff)
	{
		/* Write data to the adjusted index */
		ROM_BANK_01[addr - (unsigned char)0x4000] = data;
	}
	/* VRAM */
	else if (addr <= (unsigned short)0x9fff)
	{
		/* Write data to the adjusted index */
		VRAM[addr - (unsigned char)0x8000] = data;
	}
	/* EXTERNAL RAM */
	else if (addr <= (unsigned short)0xbfff)
	{
		/* Write data to the adjusted index */
		EXTERNAL_RAM[addr - (unsigned char)0xa000] = data;
	}
	/* WRAM_1 */
	else if (addr <= (unsigned short)0xcfff)
	{
		/* Write data to the adjusted index */
		WRAM_1[addr - (unsigned char)0xc000] = data;
	}
	/* WRAM_2 */
	else if (addr <= (unsigned short)0xdfff)
	{
		/* Write data to the adjusted index */
		WRAM_2[addr - (unsigned char)0xd000] = data;
	}
	/* ECHO_RAM */
	else if (addr <= (unsigned short)0xfdff)
	{
		/* Prohibado, I said it in Spanish, how much cleared could I have been? */
	}
	/* OAM */
	else if (addr <= (unsigned short)0xfe9f)
	{
		/* Write data to the adjusted index */
		OAM[addr - (unsigned char)0xfe00] = data;
	}
	/* No */
	else if (addr <= (unsigned short)0xfeff)
	{
	
	}
	/* IO REGISTERS */
	else if (addr <= (unsigned short)0xff7f)
	{
		/* Write data to the adjusted index */
		IO_REGISTERS[addr - (unsigned char)0xff00] = data;
	}
	/* HIGH RAM */
	else if (addr <= (unsigned short)0xfffe)
	{
		/* Write data to the adjusted index */
		HRAM[addr - (unsigned char)0xff80] = data;
	}
	/* IE REGISTER */
	else if (addr <= (unsigned short)0xffff)
	{
		/* Write data*/
		IE_REGISTER = data;
	}
	else
	{
		/* wut */
	}
}