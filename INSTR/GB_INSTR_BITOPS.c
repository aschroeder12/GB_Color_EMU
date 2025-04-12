/*  GB ROTATE / SHIFTS / BIT OPERATIONS TODO
 *  
 */

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
