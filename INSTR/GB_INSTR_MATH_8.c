/*  GB MATH INSTRUCTIONS 	
 *
 *  0x04 INC B 				- INCREMENT (REGISTER)
 *  0x05 DEC B 				- DECREMENT (REGISTER)
 *  0x0c INC C 				- INCREMENT (REGISTER)
 *  0x0d DEC C 				- DECREMENT (REGISTER)
 *  0x14 INC D 				- INCREMENT (REGISTER)
 *  0x15 DEC D 				- DECREMENT (REGISTER)
 *  0x1c INC E 				- INCREMENT (REGISTER)
 *  0x1d DEC E 				- DECREMENT (REGISTER)
 *  0x24 INC H 				- INCREMENT (REGISTER)
 *  0x25 DEC H 				- DECREMENT (REGISTER)
 *  0x27 DAA 				- DECIMAL ADJUST ACCUMULATOR
 *  0x2c INC L 				- INCREMENT (REGISTER)
 *  0x2d DEC L 				- DECREMENT (REGISTER)
 *  0x2f CPL 				- COMPLEMENT ACCUMULATOR
 *  0x34 INC HL 			- INCREMENT (INDIRECT HL)
 *  0x35 DEC HL				- DECREMENT (INDIRECT HL)
 *  0x37 SCF				- SET CARRY FLAG
 *  0x3c INC A 				- INCREMENT (REGISTER)
 *  0x3d DEC A 				- DECREMENT (REGISTER)
 *  0x3f CCF				- COMPLIMENT CARRY FLAG

 *  0x80 ADD B 				- ADD (REGISTER)
 * 	0x81 ADD C 				- ADD (REGISTER)
 * 	0x82 ADD D 				- ADD (REGISTER)
 * 	0x83 ADD E 				- ADD (REGISTER)
 * 	0x84 ADD H 				- ADD (REGISTER)
 * 	0x85 ADD L 				- ADD (REGISTER)
 * 	0x86 ADD (HL) 			- ADD (INDIRECT HL)
 * 	0x87 ADD A 				- ADD (REGISTER)
 * 	0x88 ADC B 				- ADD WITH CARRY (REGISTER)
 * 	0x89 ADC C 				- ADD WITH CARRY (REGISTER)
 * 	0x8a ADC D 				- ADD WITH CARRY (REGISTER)
 * 	0x8b ADC E 				- ADD WITH CARRY (REGISTER)
 * 	0x8c ADC H 				- ADD WITH CARRY (REGISTER)
 * 	0x8d ADC L 				- ADD WITH CARRY (REGISTER)
 * 	0x8e ADC (HL) 			- ADD WITH CARRY (INDIRECT HL)
 * 	0x8f ADC A 				- ADD WITH CARRY (REGISTER)
 *  0x90 SUB B 				- SUB (REGISTER)
 * 	0x91 SUB C 				- SUB (REGISTER)
 * 	0x92 SUB D 				- SUB (REGISTER)
 * 	0x93 SUB E 				- SUB (REGISTER)
 * 	0x94 SUB H 				- SUB (REGISTER)
 * 	0x95 SUB L 				- SUB (REGISTER)
 * 	0x96 SUB (HL) 			- SUB (INDIRECT HL)
 * 	0x97 SUB A 				- SUB (REGISTER)
 * 	0x98 SBC B 				- SUB WITH CARRY (REGISTER)
 * 	0x99 SBC C 				- SUB WITH CARRY (REGISTER)
 * 	0x9a SBC D 				- SUB WITH CARRY (REGISTER)
 * 	0x9b SBC E 				- SUB WITH CARRY (REGISTER)
 * 	0x9c SBC H 				- SUB WITH CARRY (REGISTER)
 * 	0x9d SBC L 				- SUB WITH CARRY (REGISTER)
 * 	0x9e SBC (HL) 			- SUB WITH CARRY (INDIRECT HL)
 * 	0x9f SBC A 				- SUB WITH CARRY (REGISTER)
 */

/* INC B - INCREMENT (REGISTER)
 * Increments data in the 8-bit register B
 */
void INC_B()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = B_REGISTER + 1;
	B = result;
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

/* DEC B - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register B
 */
void DEC_B()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = B_REGISTER - 1;
	B = result;
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

/* INC C - INCREMENT (REGISTER)
 * Increments data in the 8-bit register C
 */
void INC_C()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = C_REGISTER + 1;
	C = result;
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

/* DEC C - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register C
 */
void DEC_C()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = C_REGISTER - 1;
	C = result;
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

/* INC D - INCREMENT (REGISTER)
 * Increments data in the 8-bit register D
 */
void INC_D()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = D_REGISTER + 1;
	D = result;
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

/* DEC D - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register D
 */
void DEC_D()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = D_REGISTER - 1;
	D = result;
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

/* INC E - INCREMENT (REGISTER)
 * Increments data in the 8-bit register E
 */
void INC_E()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = E_REGISTER + 1;
	E = result;
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

/* DEC E - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register E
 */
void DEC_E()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = E_REGISTER - 1;
	E = result;
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

/* INC H - INCREMENT (REGISTER)
 * Increments data in the 8-bit register H
 */
void INC_H()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = H_REGISTER + 1;
	H = result;
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

/* DEC H - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register H
 */
void DEC_H()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = H_REGISTER - 1;
	H = result;
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

/* DAA - DECIMAL ADJUST ACCUMULATOR
 * Designed to be used after performing an arithmetic instruction (ADD, ADC, SUB, SBC) 
 * whose inputs were in Binary-Coded Decimal (BCD), adjusting the result to likewise be in BCD.
 */
void DAA()
{
	
}





/* INC L - INCREMENT (REGISTER)
 * Increments data in the 8-bit register L
 */
void INC_L()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = L_REGISTER + 1;
	L = result;
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

/* DEC L - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register L
 */
void DEC_L()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = L_REGISTER - 1;
	L = result;
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









/* INC A - INCREMENT (REGISTER)
 * Increments data in the 8-bit register A
 */
void INC_A()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER + 1;
	A = result;
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

/* DEC A - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register A
 */
void DEC_A()
{
	unsigned char result, carry_per_bit;
	result, carry_per_bit = A_REGISTER - 1;
	A = result;
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











/************************************************************************************************** 0x80 
 * ADD B - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register B, and stores the result back into the A register.
 */
void ADD_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + B_REGISTER;
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

/* ADD C - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register C, and stores the result back into the A register.
 */
void ADD_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + C_REGISTER;
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

/* ADD D - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register D, and stores the result back into the A register.
 */
void ADD_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + D_REGISTER;
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

/* ADD E - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register E, and stores the result back into the A register.
 */
void ADD_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + E_REGISTER;
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

/* ADD H - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register H, and stores the result back into the A register.
 */
void ADD_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + H_REGISTER;
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

/* ADD L - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register L, and stores the result back into the A register.
 */
void ADD_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + L_REGISTER;
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

/* ADD A - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register A, and stores the result back into the A register.
 */
void ADD_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + A_REGISTER;
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

/* ADC B - ADD with carry (REGISTER)
 * Adds to the 8-bit A register, the carry flag and the 8-bit register B, 
 * and stores the result back into the A register.
 */
void ADC_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + B_REGISTER + (F_REGISTER >> 7);
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

/* ADC C - ADD with carry (REGISTER)
 * Adds to the 8-bit A register, the carry flag and the 8-bit register C, 
 * and stores the result back into the A register.
 */
void ADC_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + C_REGISTER + (F_REGISTER >> 7);
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

/* ADC D - ADD with carry (REGISTER)
 * Adds to the 8-bit A register, the carry flag and the 8-bit register D, 
 * and stores the result back into the A register.
 */
void ADC_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + D_REGISTER + (F_REGISTER >> 7);
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

/* ADC E - ADD with carry (REGISTER)
 * Adds to the 8-bit A register, the carry flag and the 8-bit register E, 
 * and stores the result back into the A register.
 */
void ADC_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + E_REGISTER + (F_REGISTER >> 7);
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

/* ADC H - ADD with carry (REGISTER)
 * Adds to the 8-bit A register, the carry flag and the 8-bit register H, 
 * and stores the result back into the A register.
 */
void ADC_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + H_REGISTER + (F_REGISTER >> 7);
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

/* ADC L - ADD with carry (REGISTER)
 * Adds to the 8-bit A register, the carry flag and the 8-bit register L, 
 * and stores the result back into the A register.
 */
void ADC_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + L_REGISTER + (F_REGISTER >> 7);
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

/* ADC A - ADD with carry (REGISTER)
 * Adds to the 8-bit A register, the carry flag and the 8-bit register A, 
 * and stores the result back into the A register.
 */
void ADC_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + A_REGISTER + (F_REGISTER >> 7);
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

/************************************************************************************************** 0x90 
 * SUB B - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register B, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - B_REGISTER;
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

/* SUB C - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register C, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - C_REGISTER;
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

/* SUB D - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register D, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - D_REGISTER;
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
		F_REGISTER = F_REGISTER * HALFCARRY_RESET;
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

/* SUB E - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register E, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - E_REGISTER;
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

/* SUB H - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register H, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - H_REGISTER;
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

/* SUB L - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register L, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - L_REGISTER;
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

/* SUB A - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register A, and stores the result back into the A
 * register.
 */
void SUB_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - A_REGISTER;
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

/* SBC B - SUB with carry (REGISTER)
 * Subtracts to the 8-bit A register, the carry flag and the 8-bit register B, 
 * and stores the result back into the A register.
 */
void SBC_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - B_REGISTER - (F_REGISTER >> 7);
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

/* SBC C - SUB with carry (REGISTER)
 * Subtracts to the 8-bit A register, the carry flag and the 8-bit register C, 
 * and stores the result back into the A register.
 */
void SBC_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - C_REGISTER - (F_REGISTER >> 7);
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

/* SBC D - SUB with carry (REGISTER)
 * Subtracts to the 8-bit A register, the carry flag and the 8-bit register D, 
 * and stores the result back into the A register.
 */
void SBC_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - D_REGISTER - (F_REGISTER >> 7);
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

/* SBC E - SUB with carry (REGISTER)
 * Subtracts to the 8-bit A register, the carry flag and the 8-bit register E, 
 * and stores the result back into the A register.
 */
void SBC_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - E_REGISTER - (F_REGISTER >> 7);
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

/* SBC H - SUB with carry (REGISTER)
 * Subtracts to the 8-bit A register, the carry flag and the 8-bit register H, 
 * and stores the result back into the A register.
 */
void SBC_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - H_REGISTER - (F_REGISTER >> 7);
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

/* SBC L - SUB with carry (REGISTER)
 * Subtracts to the 8-bit A register, the carry flag and the 8-bit register L, 
 * and stores the result back into the A register.
 */
void SBC_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - L_REGISTER - (F_REGISTER >> 7);
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

/* SBC A - SUB with carry (REGISTER)
 * Subtracts to the 8-bit A register, the carry flag and the 8-bit register A, 
 * and stores the result back into the A register.
 */
void SBC_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER - A_REGISTER - (F_REGISTER >> 7);
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