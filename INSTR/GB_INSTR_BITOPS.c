/*  GB ROTATE / SHIFTS / BIT OPERATIONS TODO
 *  
 * DONE
 * 0x07 RLCA 			- ROTATE LEFT CIRCULAR (ACCUMULATOR)
 * 0x0f RRCA 			- ROTATE RIGHT CIRCULAR (ACCUMULATOR)
 * 0x17 RLA 			- ROTATE LEFT (ACCUMULATOR)
 * 0x1f RRA 			- ROTATE RIGHT (ACCUMULATOR)
 * 0xcb PREFIXED OPs WOOOOOOOOOOOOOOO
 */

/* RLCA - ROTATE LEFT CIRCULAR (ACCUMULATOR)
 * Shift the A_REGISTER bits left by 1, bit 7 into the Carry FLAG 
 * AND back around to bit 0, hence the "circular".
 */
void INSTR_RLCA(void)
{
	/* Scootch bit 7 into carry flag and back to bit 0 of A_REGISTER */
	if (A_REGISTER | ZERO_RESET == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
		A_REGISTER = A_REGISTER << 1;
		A_REGISTER = A_REGISTER | (unsigned char)0x01;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
		A_REGISTER = A_REGISTER << 1;
	}
	F_REGISTER = F_REGISTER & ZERO_RESET;
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
}

/* RRCA - ROTATE RIGHT CIRCULAR (ACCUMULATOR)
 * Shift the A_REGISTER bits right by 1, bit 0 into the Carry FLAG 
 * AND back around to bit 7, hence the "circular".
 */
void INSTR_RRCA(void)
{
	/* Scootch bit 0 into carry flag and back to bit 7 of A_REGISTER */
	if (A_REGISTER | (unsigned char)0x01 == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
		A_REGISTER = A_REGISTER >> 1;
		A_REGISTER = A_REGISTER | ZERO_SET; // set bit 7
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
		A_REGISTER = A_REGISTER >> 1;
	}
	F_REGISTER = F_REGISTER & ZERO_RESET;
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
}


/* RLA - ROTATE LEFT (ACCUMULATOR)
 * Shift the A_REGISTER bits left by 1, into the Carry Flag.
 * Carry flag goes into bit 0.
 */
void INSTR_RLA(void)
{
	/* Scootch bit 7 into carry flag */
	if (A_REGISTER | ZERO_RESET == (unsigned char)0xff)
	{
		A_REGISTER = A_REGISTER << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			A_REGISTER = A_REGISTER | 0x01;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		A_REGISTER = A_REGISTER << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			A_REGISTER = A_REGISTER | 0x01;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	F_REGISTER = F_REGISTER & ZERO_RESET;
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
}


/* RRA - ROTATE RIGHT (ACCUMULATOR)
 * Shift the A_REGISTER bits right by 1, into the Carry Flag.
 * Carry flag goes into bit 7.
 */
void INSTR_RRA(void)
{
	/* Scootch bit 0 into carry flag */
	if (A_REGISTER | (unsigned char)0x01  == (unsigned char)0xff)
	{
		A_REGISTER = A_REGISTER >> 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			A_REGISTER = A_REGISTER | ZERO_SET;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		A_REGISTER = A_REGISTER >> 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			A_REGISTER = A_REGISTER | ZERO_SET;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	F_REGISTER = F_REGISTER & ZERO_RESET;
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
}

/* RLC R - ROTATE LEFT CIRCULAR (REGISTER)
 * Shift the Register R bits left by 1, bit 7 into the Carry FLAG 
 * AND back around to bit 0, hence the "circular".
 */
void INSTR_RLC_REGISTER_R(unsigned char *R)
{
	/* Scootch bit 7 into carry flag and back to bit 0 of R */
	if (*R | ZERO_RESET == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
		*R = *R << 1;
		*R = *R | (unsigned char)0x01;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
		*R = *R << 1;
	}
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
}

/* RLC (HL) - ROTATE LEFT CIRCULAR (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL left 1 bit, bit 7 into the Carry FLAG 
 * AND back around to bit 0, hence the "circular".
 */
void INSTR_RLC_REGISTER_HL(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	/* Scootch bit 7 into carry flag and back to bit 0 of DATA_BUS */
	if (DATA_BUS | ZERO_RESET == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
		DATA_BUS = DATA_BUS << 1;
		DATA_BUS = DATA_BUS | (unsigned char)0x01;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
		DATA_BUS = DATA_BUS << 1;
	}
	if (DATA_BUS == (unsigned char)0) // Zero flag
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	WriteMemory(ADDRESS_BUS, DATA_BUS);
}

/* RRC R - ROTATE RIGHT CIRCULAR (REGISTER)
 * Shift the Register R bits right by 1, bit 0 into the Carry FLAG 
 * AND back around to bit 7, hence the "circular".
 */
void INSTR_RRC_REGISTER_R(unsigned char *R)
{
	/* Scootch bit 0 into carry flag and back to bit 7 of R */
	if (*R | (unsigned char)0x01 == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
		*R = *R >> 1;
		*R = *R | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
		*R = *R >> 1;
	}
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
}

/* RLC (HL) - ROTATE RIGHT CIRCULAR (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL right 1 bit, bit 0 into the Carry FLAG 
 * AND back around to bit 7, hence the "circular".
 */
void INSTR_RRC_REGISTER_HL(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	/* Scootch bit 7 into carry flag and back to bit 0 of A_REGISTER */
	if (DATA_BUS | (unsigned char)0x01 == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
		DATA_BUS = DATA_BUS >> 1;
		DATA_BUS = DATA_BUS | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
		DATA_BUS = DATA_BUS >> 1;
	}
	if (DATA_BUS == (unsigned char)0) // Zero flag
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	WriteMemory(ADDRESS_BUS, DATA_BUS);
}
