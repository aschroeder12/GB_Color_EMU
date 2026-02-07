#include "../MEM/GB_MEM.h"
#include "../LIB/GB_LIB.h"
#include "GB_INSTR_CB_BIT.h"

/*  GB TEST BIT DONE
 * 0xcb40 - 7f BIT 			- TEST BIT (REGISTER)
 * 0xcb80 - bf RES 			- RESET BIT (REGISTER)
 * 0xcbc0 - ff SET 			- SET BIT (REGISTER)
 */

/* BIT B - TEST BIT (REGISTER)
 * Test the bit B of the Register R.
 * Zero flag is set to 1 if the chosen bit is 0, 0 otherwise.
 */
void INSTR_BIT_REGISTER_R(unsigned char B, unsigned char *R)
{
	unsigned char tmp;
	tmp = *R << ((unsigned char)7 - B);
	tmp = tmp >> B;
	if (tmp == (unsigned char)0)
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER | HALFCARRY_SET;
}

/* BIT B - TEST BIT (INDIRECT HL)
 * Tests the bit b of the 8-bit data at the absolute address specified by the 16-bit register HL
 * Zero flag is set to 1 if the chosen bit is 0, 0 otherwise.
 */
void INSTR_BIT_REGISTER_HL(unsigned char B)
{
	unsigned char tmp;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	tmp = DATA_BUS << ((unsigned char)7 - B);
	tmp = tmp >> B;
	if (tmp == (unsigned char)0)
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER | HALFCARRY_SET;
	WriteMemory(ADDRESS_BUS, DATA_BUS);
}

/* RES B - RESET BIT (REGISTER)
 * Reset the bit B of Register R to 0. 
 */
void INSTR_RES_REGISTER_R(unsigned char B, unsigned char *R)
{
	unsigned char tmp;
	tmp = (unsigned char)0xff;
	tmp = tmp << ((unsigned char)7 - B);
	tmp = tmp >> B;
	tmp = tmp ^ (unsigned char)0xff;
	*R = *R & tmp;
}

/* RES B - RESET BIT (INDIRECT HL)
 * Resets the bit b of the 8-bit data at the absolute address specified by the 16-bit register HL, to 0
 */
void INSTR_RES_REGISTER_HL(unsigned char B)
{
	unsigned char tmp;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	tmp = (unsigned char)0xff;
	tmp = tmp << ((unsigned char)7 - B);
	tmp = tmp >> B;
	tmp = tmp ^ (unsigned char)0xff;
	DATA_BUS = DATA_BUS & tmp;
	WriteMemory(ADDRESS_BUS, DATA_BUS);
}

/* SET B - SET BIT (REGISTER)
 * Set the bit B of Register R to 1. 
 */
void INSTR_SET_REGISTER_R(unsigned char B, unsigned char *R)
{
	unsigned char tmp;
	tmp = (unsigned char)0xff;
	tmp = tmp << ((unsigned char)7 - B);
	tmp = tmp >> B;
	*R = *R | tmp;
}

/* SET B - SET BIT (INDIRECT HL)
 * Sets the bit b of the 8-bit data at the absolute address specified by the 16-bit register HL, to 1
 */
void INSTR_SET_REGISTER_HL(unsigned char B)
{
	unsigned char tmp;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	tmp = (unsigned char)0xff;
	tmp = tmp << ((unsigned char)7 - B);
	tmp = tmp >> B;
	DATA_BUS = DATA_BUS | tmp;
	WriteMemory(ADDRESS_BUS, DATA_BUS);
}
