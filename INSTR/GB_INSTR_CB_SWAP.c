/*  GB SWAP
 * 0xcb30 - 37 SWAP 			- SWAP NIBBLES (REGISTER)
 */

/* SWAP R - SWAP NIBBLES (REGISTER)
 * Swaps the high and low 4-bit nibbles of the 8-bit register R
 */
void INSTR_SWAP_REGISTER_R(unsigned char *R)
{
	unsigned char a;
	unsigned char b;

	a = *R >> 4;
	b = *R << 4;
	*R = a | b;
	if (*R == (unsigned char)0) // Zero flag
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* SWAP R - SWAP NIBBLES (INDIRECT HL)
 * Swaps the high and low 4-bit nibbles of the 8-bit data at the absolute address specified by the
 * 16-bit register HL.
 */
void INSTR_SWAP_REGISTER_R(void)
{
	unsigned char a;
	unsigned char b;

	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	a = *R >> 4;
	b = *R << 4;
	*R = a | b;
	if (*R == (unsigned char)0) // Zero flag
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	F_REGISTER = F_REGISTER & CARRY_RESET;
	WriteMemory(ADDRESS_BUS, DATA_BUS);
}

