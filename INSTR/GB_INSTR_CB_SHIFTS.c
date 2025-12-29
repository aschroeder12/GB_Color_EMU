/*  GB ROTATE AND SHIFTS DONE
 * 0xcb00 - 07 RLC 			- ROTATE LEFT CIRCULAR (REGISTER)
 * 0xcb08 - 0f RRC 			- ROTATE RIGHT CIRCULAR (REGISTER)
 * 0xcb10 - 17 RL 			- ROTATE LEFT (REGISTER)
 * 0xcb18 - 1f RR 			- ROTATE RIGHT (REGISTER)
 * 0xcb20 - 27 SLA 			- SHIFT LEFT ARITHMETICALLY (REGISTER)
 * 0xcb28 - 2f SRA 			- SHIFT RIGHT ARITHMETICALLY (REGISTER)
 */

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
	if (*R | (unsigned char)0xfe == (unsigned char)0xff)
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

/* RRC (HL) - ROTATE RIGHT CIRCULAR (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL right 1 bit, bit 0 into the Carry FLAG 
 * AND back around to bit 7, hence the "circular".
 */
void INSTR_RRC_REGISTER_HL(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	/* Scootch bit 0 into carry flag and back to bit 7 of HL */
	if (DATA_BUS | (unsigned char)0xfe == (unsigned char)0xff)
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

/* RL - ROTATE LEFT (REGISTER)
 * Shift the Register R bits left by 1, into the Carry Flag.
 * Carry flag goes into bit 0.
 */
void INSTR_RL_REGISTER_R(unsigned char *R)
{
	/* Scootch bit 7 into carry flag */
	if (*R | ZERO_RESET == (unsigned char)0xff)
	{
		*R = *R << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			*R = *R | 0x01;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		*R = *R << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			*R = *R | 0x01;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (*R == (unsigned char)0)
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

/* RL - ROTATE LEFT (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL left by 1, into the Carry Flag.
 * Carry flag goes into bit 0.
 */
void INSTR_RL_REGISTER_HL(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	/* Scootch bit 7 into carry flag */
	if (DATA_BUS | ZERO_RESET == (unsigned char)0xff)
	{
		DATA_BUS = DATA_BUS << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			DATA_BUS = DATA_BUS | 0x01;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		DATA_BUS = DATA_BUS << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			DATA_BUS = DATA_BUS | 0x01;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (DATA_BUS == (unsigned char)0)
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

/* RR - ROTATE RIGHT (REGISTER)
 * Shift the Register R bits right by 1, into the Carry Flag.
 * Carry flag goes into bit 7.
 */
void INSTR_RR_REGISTER_R(unsigned char *R)
{
	/* Scootch bit 0 into carry flag */
	if (*R | (unsigned char)0xfe  == (unsigned char)0xff)
	{
		*R = *R >> 1;
		/* Wrap carry flag into bit 7, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			*R = *R | ZERO_SET;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		*R = *R >> 1;
		/* Wrap carry flag into bit 7, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			*R = *R | ZERO_SET;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (*R == (unsigned char)0)
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

/* RR - ROTATE RIGHT (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL bits right by 1, into the Carry Flag.
 * Carry flag goes into bit 7.
 */
void INSTR_RR_REGISTER_HL(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	/* Scootch bit 0 into carry flag */
	if (DATA_BUS | (unsigned char)0xfe  == (unsigned char)0xff)
	{
		DATA_BUS = DATA_BUS >> 1;
		/* Wrap carry flag into bit 7, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			DATA_BUS = DATA_BUS | ZERO_SET;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		DATA_BUS = DATA_BUS >> 1;
		/* Wrap carry flag into bit 7, it'll be 0 otherwise */
		if (F_REGISTER | CARRY_RESET == (unsigned char)0xff)
		{
			DATA_BUS = DATA_BUS | ZERO_SET;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (DATA_BUS == (unsigned char)0)
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

/* SLA - SHIFT LEFT ARITHMETIC (REGISTER)
 * Shift the Register R value left by one bit using an arithmetic shift
 * Bit 7 goes into Carry Flag, bit 0 is set to 0. 
 */
void INSTR_SLA_REGISTER_R(unsigned char *R)
{
	/* Scootch bit 7 into carry flag */
	if (*R | ZERO_RESET == (unsigned char)0xff)
	{
		*R = *R << 1;
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		*R = *R << 1;
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (*R == (unsigned char)0)
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

/* SLA - SHIFT LEFT ARITHMETIC (INDIRECT HL)
 * Shift the 8-bit value at the address specified by the HL register left by one bit using an arithmetic shift
 * Bit 7 goes into Carry Flag, bit 0 is set to 0. 
 */
void INSTR_SLA_REGISTER_HL(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	/* Scootch bit 7 into carry flag */
	if (DATA_BUS | ZERO_RESET == (unsigned char)0xff)
	{
		DATA_BUS = DATA_BUS << 1;
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		DATA_BUS = DATA_BUS << 1;
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (DATA_BUS == (unsigned char)0)
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

/* SRA - SHIFT RIGHT ARITHMETIC (REGISTER)
 * Shift the Register R value right by 1, into the Carry Flag.
 * Bit 7 retains its value, bit 0 to Carry Flag.
 */
void INSTR_SRA_REGISTER_R(unsigned char *R)
{
	/* Scootch bit 0 into carry flag */
	if (*R | (unsigned char)0xfe  == (unsigned char)0xff)
	{
		/* If bit 7 is 1, keep that value in bit 7 after the shift */
		if (*R | ZERO_RESET == (unsigned char)0xff)
		{
			*R = *R >> 1;
			*R = *R | ZERO_SET;
		}
		else
		{
			*R = *R >> 1;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		/* If bit 7 is 1, keep that value in bit 7 after the shift */
		if (*R | ZERO_RESET == (unsigned char)0xff)
		{
			*R = *R >> 1;
			*R = *R | ZERO_SET;
		}
		else
		{
			*R = *R >> 1;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (*R == (unsigned char)0)
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

/* SRA - SHIFT RIGHT ARITHMETIC (INDIRECT HL)
 * Shift the 8-bit value at the address specified by the HL register right by 1, into the Carry Flag.
 * Bit 7 retains its value, bit 0 to Carry Flag.
 */
void INSTR_SRA_REGISTER_HL(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	/* Scootch bit 0 into carry flag */
	if (DATA_BUS | (unsigned char)0xfe  == (unsigned char)0xff)
	{
		/* If bit 7 is 1, keep that value in bit 7 after the shift */
		if (DATA_BUS | ZERO_RESET == (unsigned char)0xff)
		{
			DATA_BUS = DATA_BUS >> 1;
			DATA_BUS = DATA_BUS | ZERO_SET;
		}
		else
		{
			DATA_BUS = DATA_BUS >> 1;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		/* If bit 7 is 1, keep that value in bit 7 after the shift */
		if (DATA_BUS | ZERO_RESET == (unsigned char)0xff)
		{
			DATA_BUS = DATA_BUS >> 1;
			DATA_BUS = DATA_BUS | ZERO_SET;
		}
		else
		{
			DATA_BUS = DATA_BUS >> 1;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	if (DATA_BUS == (unsigned char)0)
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