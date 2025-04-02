/*  GB LOGICAL INSTRUCTIONS DONE
 *  0xa0 - 0xa5, 0xa7		- AND (REGISTER)
 * 	0xa6 AND (HL) 			- AND (INDIRECT HL)
 * 	0xa8 - 0xad, 0xaf 		- BITWISE XOR (REGISTER)
 * 	0xae XOR (HL) 			- BITWISE XOR (INDIRECT HL)
 *  0xb0 - 0xb5, 0xb7 		- OR (REGISTER)
 * 	0xb6 OR (HL) 			- OR (INDIRECT HL)
 * 	0xb8 - 0xbd, 0xbf 		- COMPARE (REGISTER)
 * 	0xbe CP (HL) 			- COMPARE (INDIRECT HL)
 *  0xe6 AND n 				- AND (IMMEDIATE)
 *  0xee XOR n 				- XOR (IMMEDIATE)
 *  0xf6 OR n 				- OR (IMMEDIATE)
 *  0xfe CP n 				- COMPARE (IMMEDIATE)
 *  0x2f CPL 				- COMPLIMENT ACCUMULATOR
 *  0x3f CCF 				- COMPLIMENT CARRY FLAG
 *  0x37 SCF 				- SET CARRY FLAG
 */

/* AND R - AND (REGISTER) 0xa0 - 0xa5, 0xa7
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register r, and
 * stores the result back into the A register.
 */
void AND_REGISTER_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER & *R;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER | HALFCARRY_SET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* AND N - AND (IMMEDIATE)
 * Performs a bitwise AND operation between the 8-bit A register and immediate data n, and
 * stores the result back into the A register.
 */
void AND_N()
{
	unsigned char result, carry_per_bit, data;
	data = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result, carry_per_bit = A_REGISTER & data;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER | HALFCARRY_SET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}


/* AND HL - AND (INDIRECT HL)
 * Performs a bitwise AND operation between the 8-bit A register and data from the absolute
 * address specified by the 16-bit register HL, and stores the result back into the A register.
 */
void AND_REGISTER_HL()
{
	unsigned char result, carry_per_bit;

	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER & DATA_BUS;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER | HALFCARRY_SET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* XOR R - XOR (REGISTER) 0xa8 - 0xad, 0xaf
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register R, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER ^ *R;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* XOR L - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and data from the absolute 
 * address specified by the 16-bit register HL, and stores the result back into the A register
 */
void XOR_REGISTER_HL()
{
	unsigned char result, carry_per_bit;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER ^ DATA_BUS;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* OR R - OR (REGISTER) 0xb0 - 0xb5, 0xb7
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register R, and
 * stores the result back into the A register.
 */
void OR_REGISTER_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER | *R;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* OR N - OR (IMMEDIATE)
 * Performs a bitwise OR operation between the 8-bit A register and immediate data n, and stores
 * the result back into the A register.
 */
void OR_N()
{
	unsigned char result, carry_per_bit, data;
	data = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result, carry_per_bit = A_REGISTER | data;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* OR HL - OR (INDIRECT HL)
 * Performs a bitwise OR operation between the 8-bit A register and data from the absolute
 * address specified by the 16-bit register HL, and stores the result back into the A register.
 */
void OR_REGISTER_HL()
{
	unsigned char result, carry_per_bit;

	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER | DATA_BUS;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* CP R - CP (REGISTER) 0xb8 - 0xbd, 0xbf
 * Subtracts from the 8-bit A register, the 8-bit register R, and updates flags based on the result.
 * This instruction is basically identical to SUB B, but does not update the A register.
 */
void CP_REGISTER_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER - *R;
	// debug the carry_per_bit to make sure it works
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER | SUBTRACTION_SET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
}

/* CP HL - CP (INDIRECT HL)
 * Subtracts from the 8-bit A register, data from the absolute address specified by the 16-bit
 * register HL, and updates flags based on the result. This instruction is basically identical to 
 * SUB (HL), but does not update the A register.
 */
void CP_REGISTER_HL()
{
	unsigned char result, carry_per_bit;

	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER - DATA_BUS;
	// debug the carry_per_bit to make sure it works
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER | SUBTRACTION_SET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
}

/* XOR n - XOR (IMMEDIATE)
 * Performs a bitwise XOR operation between the 8-bit A register and immediate data n, and
 * stores the result back into the A register.
 */
void XOR_N(void)
{
	unsigned char n, result;
	n = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result = A_REGISTER ^ n;
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* CP n - COMPARE (IMMEDIATE)
 * Subtracts from the 8-bit A register, the immediate data n, and updates flags based on the result.
 * This instruction is basically identical to SUB n, but does not update the A register
 */
void CP_N(void)
{
	unsigned char n, result, carry_per_bit;
	n = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result, carry_per_bit = A_REGISTER - n;
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
}

/* CPL - COMPLIMENT ACCUMULATOR
 * Flips all the bits in the 8-bit A register, and sets the N and H flags.
 */
void CPL()
{
	A_REGISTER = ~A_REGISTER;
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER | SUBTRACTION_SET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER | HALFCARRY_SET;
}

/* CCF - COMPLIMENT CARRY FLAG
 * Flips the carry flag, and clears the N and H flags
 */
void CCF()
{
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Flip the Carry Flag by seeing if it is set */
	if (F_REGISTER | CARRY_SET == F_REGISTER)
	{
		/* If set, reset it */
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	else
	{
		/* If not set, set it */
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
}

/* SCF - SET CARRY FLAG
 * Sets the carry flag, and clears the N and H flags
 */
void SCF()
{
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER | CARRY_SET;
}

