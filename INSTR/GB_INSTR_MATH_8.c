/*  GB 8-BIT MATH INSTRUCTIONS TODO
 * 
 *  0x27 DAA 				- DECIMAL ADJUST ACCUMULATOR
 *  0x2f CPL 				- COMPLEMENT ACCUMULATOR
 *  0x37 SCF				- SET CARRY FLAG

 *  0x3f CCF				- COMPLIMENT CARRY FLAG
 I'm missing the above instructions, but you can trust the excel now

 *  various INC R 			- INCREMENT (REGISTER)
 *  various DEC R 			- DECREMENT (REGISTER)
 *  0x34 INC HL 			- INCREMENT (INDIRECT HL)
 *  0x35 DEC HL				- DECREMENT (INDIRECT HL)

 *  0x80 - 0x85, 0x87 		- ADD (REGISTER)
 * 	0x86 ADD (HL) 			- ADD (INDIRECT HL)
 *  0x88 - 0x8d, 0x8f		- ADD WITH CARRY (REGISTER)
 *  0x8e ADC (HL)			- ADD WITH CARRY (INDIRECT HL)
 *  0x90 - 0x95, 0x97 		- SUBTRACT (REGISTER)
 *  0x96 SUB (HL)			- SUBTRACT (INDIRECT HL)
 *  0x98 - 0x9d, 0x9f		- SUBTRACT WITH CARRY (REGISTER)
 * 	0x9e SBC (HL) 			- SUBTRACT WITH CARRY (INDIRECT HL)
 *  0xc6 AND N 				- ADD (IMMEDIATE)
 *  0xd6 SUB N 				- SUBTRACT (IMMEDIATE)
 *  0xce ADC N 				- ADD WITH CARRY (IMMEDIATE)
 *  0xde SBC N 				- SUBTRACT WITH CARRY (IMMEDIATE)
 */

/* INC R - INCREMENT (REGISTER)
 * Increments data in the 8-bit register R
 */
void INC_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = *R + 1;
	*R = result;
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
}

/* INC HL - INCREMENT (INDIRECT HL)
 * Increments data at the absolute address specified by the 16-bit register HL.
 */
void INC_HL()
{
	unsigned char result, data, carry_per_bit;
	unsigned short addr;

	addr = (unsigned short)(H_REGISTER << 8) + (unsigned short)L_REGISTER;
	data = ReadMemory(addr);
	result, carry_per_bit = data + 1;
	WriteMemory(addr, result)
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
}

/* DEC R - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register R
 */
void DEC_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = *R - 1;
	*R = result;
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
}

/* DEC HL - DECREMENT (INDIRECT HL)
 * Decrements data at the absolute address specified by the 16-bit register HL.
 */
void DEC_HL()
{
	unsigned char result, data, carry_per_bit;
	unsigned short addr;

	addr = (unsigned short)(H_REGISTER << 8) + (unsigned short)L_REGISTER;
	data = ReadMemory(addr);
	result, carry_per_bit = data - 1;
	WriteMemory(addr, result)
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
}


/* DAA - DECIMAL ADJUST ACCUMULATOR
 * Designed to be used after performing an arithmetic instruction (ADD, ADC, SUB, SBC) 
 * whose inputs were in Binary-Coded Decimal (BCD), adjusting the result to likewise be in BCD.
 TODO
 */
void DAA()
{
	
}

/* ADD n - ADD (IMMEDIATE) 0xc6
 * Adds to the 8-bit A register, the immediate data n, and stores the result back into the A register.
 */
void ADD_N()
{
	unsigned char result, carry_per_bit, data;
	data = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result, carry_per_bit = A_REGISTER + data;
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


/* ADD r - ADD (REGISTER) 0x80 - 0x85, 0x87
 * Adds to the 8-bit A register, the 8-bit register r, and stores the result back into the A register.
 */
void ADD_REGISTER_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER + *R;
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

/* ADD HL - ADD (INDIRECT HL)
 * Adds to the 8-bit A register, data from the absolute address specificed by the 16-bit register HL, 
 * and stores the result back into the A register.
 */
void ADD_REGISTER_HL()
{
	unsigned char result, carry_per_bit;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER + DATA_BUS;
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

/* ADC N - ADD WITH CARRY (IMMEDIATE) 
 * Adds to the 8-bit A register, the carry flag and the immediate data n, and stores the result back
 * into the A register.
 */
void ADC_N()
{
	unsigned char result, carry_per_bit, data;
	data = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result, carry_per_bit = A_REGISTER + data + (F_REGISTER >> 7);
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


/* ADC R - ADD WITH CARRY (REGISTER) 0x88 - 0x8d, 0x8f
 * Adds to the 8-bit A register, the carry flag and the 8-bit register r, and stores the result back
 * into the A register.
 */
void ADC_REGISTER_R(unsigned char* R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER + *R + (F_REGISTER >> 7);
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

/* ADC HL - ADD with carry (INDIRECT HL)
 * Adds to the 8-bit A register, the carry flag and the data from the absolute address specified
 * by the 16-bit register HL, and stores the result back into the A register.
 */
void ADC_REGISTER_HL()
{
	unsigned char result, carry_per_bit;

	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER + DATA_BUS + (F_REGISTER >> 7);
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

/* SUB n - SUBTRACT (IMMEDIATE) 0xd6
 * Subtracts from the 8-bit A register, the immediate data n, and stores the result back into the A
 * register.
 */
void SUB_N()
{
	unsigned char result, carry_per_bit, data;
	data = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result, carry_per_bit = A_REGISTER - data;
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


/* SUB R - SUBTRACT (REGISTER) 0x90 - 0x95, 0x97
 * Subtracts from the 8-bit A register, the 8-bit register r, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_R(unsigned char* R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER - *R;
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

/* SUB HL - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register HL, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_HL()
{
	unsigned char result, carry_per_bit;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	result, carry_per_bit = A_REGISTER - DATA_BUS;
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

/* SBC N - SUBTRACT WITH CARRY (IMMEDIATE) 
 * Subtracts from the 8-bit A register, the carry flag and the immediate data n, and stores the
 * result back into the A register.
 */
void SBC_N()
{
	unsigned char result, carry_per_bit, data;
	data = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result, carry_per_bit = A_REGISTER - data - (F_REGISTER >> 7);
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

/* SBC R - SUBTRACT WITH CARRY (REGISTER) 0x98 - 0x9d, 0x9f
 * Subtracts from the 8-bit A register, the carry flag and the 8-bit register r, and stores the result
 * back into the A register.
 */
void SBC_REGISTER_R(unsigned char *R)
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER - *R - (F_REGISTER >> 7);
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

/* SBC HL - SUB with carry (INDIRECT HL)
 * Subtracts to the 8-bit A register, the carry flag and the data from the absolute address specified
 * by the 16-bit register HL, and stores the result back into the A register.
 */
void SBC_REGISTER_HL()
{
	unsigned char result, carry_per_bit;

	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER - DATA_BUS - (F_REGISTER >> 7);
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

