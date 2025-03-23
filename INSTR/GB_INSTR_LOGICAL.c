/*  GB LOGICAL INSTRUCTIONS DONE?
 *
 *  0xa0 AND B 				- AND (REGISTER)
 * 	0xa1 AND C 				- AND (REGISTER)
 * 	0xa2 AND D 				- AND (REGISTER)
 * 	0xa3 AND E 				- AND (REGISTER)
 * 	0xa4 AND H 				- AND (REGISTER)
 * 	0xa5 AND L 				- AND (REGISTER)
 * 	0xa6 AND (HL) 			- AND (INDIRECT HL)
 * 	0xa7 AND A 				- AND (REGISTER)
 * 	0xa8 XOR B 				- BITWISE XOR (REGISTER)
 * 	0xa9 XOR C 				- BITWISE XOR (REGISTER)
 * 	0xaa XOR D 				- BITWISE XOR (REGISTER)
 * 	0xab XOR E 				- BITWISE XOR (REGISTER)
 * 	0xac XOR H 				- BITWISE XOR (REGISTER)
 * 	0xad XOR L 				- BITWISE XOR (REGISTER)
 * 	0xae XOR (HL) 			- BITWISE XOR (INDIRECT HL)
 * 	0xaf XOR A 				- BITWISE XOR (REGISTER)
 * 
 *  0xb0 OR B 				- OR (REGISTER)
 * 	0xb1 OR C 				- OR (REGISTER)
 * 	0xb2 OR D 				- OR (REGISTER)
 * 	0xb3 OR E 				- OR (REGISTER)
 * 	0xb4 OR H 				- OR (REGISTER)
 * 	0xb5 OR L 				- OR (REGISTER)
 * 	0xb6 OR (HL) 			- OR (INDIRECT HL)
 * 	0xb7 OR A 				- OR (REGISTER)
 * 	0xb8 CP B 				- COMPARE (REGISTER)
 * 	0xb9 CP C 				- COMPARE (REGISTER)
 * 	0xba CP D 				- COMPARE (REGISTER)
 * 	0xbb CP E 				- COMPARE (REGISTER)
 * 	0xbc CP H 				- COMPARE (REGISTER)
 * 	0xbd CP L 				- COMPARE (REGISTER)
 * 	0xbe CP (HL) 			- COMPARE (INDIRECT HL)
 * 	0xbf CP A 				- COMPARE (REGISTER)
 * 
 *  0xe6 AND n 				- AND (IMMEDIATE)
 *  0xee XOR n 				- XOR (IMMEDIATE)
 *  0xf6 OR n 				- OR (IMMEDIATE)
 *  0xfe CP n 				- COMPARE (IMMEDIATE)
 */

/************************************************************************************************** 0xa0 
 * AND B - AND (REGISTER)
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register B, and
 * stores the result back into the A register.
 */
void AND_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER & B_REGISTER;
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

/* AND C - AND (REGISTER)
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register C, and
 * stores the result back into the A register.
 */
void AND_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER & C_REGISTER;
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

/* AND D - AND (REGISTER)
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register D, and
 * stores the result back into the A register.
 */
void AND_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER & D_REGISTER;
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
	F_REGISTER = F_REGISTER | SUBTRACTION_SET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	F_REGISTER = F_REGISTER | HALFCARRY_SET;
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	F_REGISTER = F_REGISTER & CARRY_RESET;
}

/* AND E - AND (REGISTER)
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register E, and
 * stores the result back into the A register.
 */
void AND_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER & E_REGISTER;
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

/* AND H - AND (REGISTER)
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register H, and
 * stores the result back into the A register.
 */
void AND_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER & H_REGISTER;
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

/* AND L - AND (REGISTER)
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register L, and
 * stores the result back into the A register.
 */
void AND_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER & L_REGISTER;
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

/* AND A - AND (REGISTER)
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register A, and
 * stores the result back into the A register.
 */
void AND_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER & A_REGISTER;
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

/* XOR B - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register B, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER ^ B_REGISTER;
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

/* XOR C - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register C, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER ^ C_REGISTER;
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

/* XOR D - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register D, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER ^ D_REGISTER;
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

/* XOR E - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register E, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER ^ E_REGISTER;
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

/* XOR H - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register H, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER ^ H_REGISTER;
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
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register L, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER ^ L_REGISTER;
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

/* XOR A - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register A, and
 * stores the result back into the A register.
 */
void XOR_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER ^ A_REGISTER;
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

/************************************************************************************************** 0xb0 
 * OR B - OR (REGISTER)
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register B, and
 * stores the result back into the A register.
 */
void OR_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER | B_REGISTER;
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

/* OR C - OR (REGISTER)
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register C, and
 * stores the result back into the A register.
 */
void OR_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER | C_REGISTER;
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

/* OR D - OR (REGISTER)
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register D, and
 * stores the result back into the A register.
 */
void OR_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER | D_REGISTER;
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

/* OR E - OR (REGISTER)
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register E, and
 * stores the result back into the A register.
 */
void OR_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER | E_REGISTER;
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

/* OR H - OR (REGISTER)
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register H, and
 * stores the result back into the A register.
 */
void OR_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER | H_REGISTER;
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

/* OR L - OR (REGISTER)
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register L, and
 * stores the result back into the A register.
 */
void OR_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER | L_REGISTER;
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

/* OR A - OR (REGISTER)
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register A, and
 * stores the result back into the A register.
 */
void OR_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER | A_REGISTER;
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

/* CP B - CP (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register B, and updates flags based on the result.
 * This instruction is basically identical to SUB B, but does not update the A register.
 */
void CP_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - B_REGISTER;
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

/* CP C - CP (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register C, and updates flags based on the result.
 * This instruction is basically identical to SUB C, but does not update the A register.
 */
void CP_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - C_REGISTER;
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

/* CP D - CP (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register D, and updates flags based on the result.
 * This instruction is basically identical to SUB D, but does not update the A register.
 */
void CP_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - D_REGISTER;
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

/* CP E - CP (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register E, and updates flags based on the result.
 * This instruction is basically identical to SUB E, but does not update the A register.
 */
void CP_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - E_REGISTER;
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

/* CP H - CP (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register H, and updates flags based on the result.
 * This instruction is basically identical to SUB H, but does not update the A register.
 */
void CP_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - H_REGISTER;
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

/* CP L - CP (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register L, and updates flags based on the result.
 * This instruction is basically identical to SUB L, but does not update the A register.
 */
void CP_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - L_REGISTER;
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

/* CP A - CP (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register A, and updates flags based on the result.
 * This instruction is basically identical to SUB A, but does not update the A register.
 */
void CP_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - A_REGISTER;
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

/* AND n - AND (IMMEDIATE)
 * Performs a bitwise AND operation between the 8-bit A register and immediate data n, and
 * stores the result back into the A register.
 */
void AND_N(void)
{
	unsigned char n, result;
	n = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result = A_REGISTER & n;
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

/* OR n - OR (IMMEDIATE)
 * Performs a bitwise OR operation between the 8-bit A register and immediate data n, and
 * stores the result back into the A register.
 */
void OR_N(void)
{
	unsigned char n, result;
	n = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result = A_REGISTER | n;
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
