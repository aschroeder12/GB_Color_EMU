/*  GB CONTROL FLOW INSTRUCTIONS 
 *
 *  0xc0 RET NZ 				- RETURN (CONDITIONAL)
 *  0xc2 JP NZ, nn				- JUMP (CONDITIONAL)
 *  0xc3 JP nn					- JUMP
 *  0xc4 CALL NZ, nn			- CALL FUNCTION (CONDITIONAL)
 *  0xc7 RST 0x00				- RESTART / CALL FUNCTION (IMPLIED)
 *  0xc8 RET Z 					- RETURN (CONDITIONAL)
 *  0xc9 RET 					- RETURN
 *  0xca JP Z, nn 				- JUMP (CONDITIONAL)
 *  0xcc CALL Z, nn 			- CALL FUNCTION (CONDITIONAL)
 *  0xcd CALL nn 				- CALL FUNCTION
 *  0xcf RST 0x08				- RESTART / CALL FUNCTION (IMPLIED)
 */

/* RET NZ - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the NON-ZERO condition.
 */
void RETURN_NZ(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	/* If Zero Flag not set, set PC to new address specified by the Stack Pointer 
	 * See CALL instruction for how this return Address is stored */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0x7f)
	{
		lsb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
		msb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1;
		addr = (unsigned short)(msb << 8) + (unsigned short)lsb;
		PC_REGISTER = addr;
	}
}

/* JP NZ - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the NON-ZERO condition.
 */
void JUMP_NZ(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	lsb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;

	/* If Zero Flag not set, set PC to new address */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0x7f)
	{
		PC_REGISTER = addr;
	}
}

/* JP - JUMP
 * Unconditional jump to the absolute address specified by the 16-bit immediate operand.
 */
void JUMP(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	lsb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;
	PC_REGISTER = addr;
}

/* CALL NZ - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the NON-ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_NZ(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;
	unsigned char tmp;

	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;

	/* If Zero Flag not set, create the Return Address from the current PC, write it to SP, 
	 * then set the PC to the newly called function */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0x7f)
	{
		SP_REGISTER = SP_REGISTER - 1;
		tmp = PC_REGISTER >> 8;
		WriteMemory(SP_REGISTER, tmp);
		SP_REGISTER = SP_REGISTER - 1; 
		tmp = PC_REGISTER;
		WriteMemory(SP_REGISTER, tmp);
		PC_REGISTER = addr;
	}
}

/* RST 0x00 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x00.
 */
void RESTART_00(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0000 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0000;
}

/* RET Z - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the ZERO condition.
 */
void RETURN_Z(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	/* If Zero Flag set, set PC to new address specified by the Stack Pointer 
	 * See CALL instruction for how this return Address is stored */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		lsb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
		msb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1;
		addr = (unsigned short)(msb << 8) + (unsigned short)lsb;
		PC_REGISTER = addr;
	}
}

/* RET - RETURN 
 * Unconditional return from a function
 */
void RETURN(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	/* Set PC to new address specified by the Stack Pointer 
	 * See CALL instruction for how this return Address is stored */

	lsb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;
	PC_REGISTER = addr;
}

/* JP Z - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void JUMP_Z(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	lsb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;

	/* If Zero Flag set, set PC to new address */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		PC_REGISTER = addr;
	}
}

/* CALL Z - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_Z(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;
	unsigned char tmp;

	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;

	/* If Zero Flag set, create the Return Address from the current PC, write it to SP, 
	 * then set the PC to the newly called function */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		SP_REGISTER = SP_REGISTER - 1;
		tmp = PC_REGISTER >> 8;
		WriteMemory(SP_REGISTER, tmp);
		SP_REGISTER = SP_REGISTER - 1; 
		tmp = PC_REGISTER;
		WriteMemory(SP_REGISTER, tmp);
		PC_REGISTER = addr;
	}
}

/* CALL - CALL FUNCTION
 * Unconditional function call to the absolute address specified by the 16-bit operand.
 */
void CALL(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;
	unsigned char tmp;

	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;

	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = addr;
}

/* RST 0x08 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x08.
 */
void RESTART_08(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0008 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0008;
}


