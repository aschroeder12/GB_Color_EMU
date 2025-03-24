/* GB 16-Bit MATH INSTRUCTIONS DONE!
 * INC, DEC, ADD HL (RR)
 */

/* INC rr - INCREMENT (16-BIT REGISTER, except SP)
 * Increments data in the 16-bit register rr. MSB is R1, LSB is R2!
 */
void INC_RR(unsigned char *R1, unsigned char *R2)
{	
	unsigned short val;
	val = (unsigned short)(*R1 << 8) + (unsigned short)*R2;
	val = val + 1;
	*R1 = val >> 8;
	*R2 = val;
}

/* INC SP - INCREMENT (SP REGISTER)
 * Increments data in the SP Register
 */
void INC_SP()
{
	SP_REGISTER = SP_REGISTER + 1;
}

/* DEC rr - DECREMENT (16-BIT REGISTER, except SP)
 * Decrements data in the 16-bit register rr. MSB is R1, LSB is R2!
 */
void DEC_RR(unsigned char *R1, unsigned char *R2)
{	
	unsigned short val;
	val = (unsigned short)(*R1 << 8) + (unsigned short)*R2;
	val = val - 1;
	*R1 = val >> 8;
	*R2 = val;
}

/* DEC SP - DECREMENT (SP REGISTER)
 * Decrements data in the SP Register
 */
void DEC_SP()
{
	SP_REGISTER = SP_REGISTER - 1;
}

/* ADD HL, rr - ADD (16-BIT REGISTER, except SP)
 * Adds to the 16-bit HL register pair, the 16-bit register rr, and 
 * stores the result back into the HL register pair.
 * R1 is MSB, R2 is LSB
 * I might be able to get away with doing it the way I am.
 * If there are issues, you need to add L and C first, then
 * calculate the carry bit, then also add that to H + B. 
 */
void ADD_HL_RR(unsigned char *R1, unsigned char *R2)
{
	unsigned short result, carry_per_bit, val1, val2;
	/* Get HL and RR */
	val1 = (unsigned short)(*R1 << 8) + (unsigned short)*R2;
	val2 = (unsigned short)(H_REGISTER << 8) + (unsigned short)L_REGISTER;
	result, carry_per_bit = val1 + val2;
	/* Put HL + RR back into HL */
	H_REGISTER = result >> 8;
	L_REGISTER = result;
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned short)0xf7ff) == (unsigned short)0xffff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned short)0x7fff) == (unsigned short)0xffff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
}

/* ADD HL, SP - ADD (SP)
 * Adds to the 16-bit HL register pair, the SP REGISTER, and stores the result back into the HL
 * register pair.
 */
void ADD_HL_SP()
{
	unsigned short result, carry_per_bit, val;
	val = (unsigned short)(H_REGISTER << 8) + (unsigned short)L_REGISTER;
	result, carry_per_bit = SP_REGISTER + val;
	H_REGISTER = result >> 8;
	L_REGISTER = result;
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned short)0xf7ff) == (unsigned short)0xffff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned short)0x7fff) == (unsigned short)0xffff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
}
