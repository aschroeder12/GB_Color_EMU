/*  GB CONTROL FLOW INSTRUCTIONS 
 *
 *  0x18 JR e 					- JUMP RELATIVE
 *  0x20 JR NZ, e				- JUMP RELATIVE (CONDITIONAL)
 *  0x28 JR Z, e 				- JUMP RELATIVE (CONDITIONAL)
 *  0x30 JR NC, e				- JUMP RELATIVE (CONDITIONAL)
 *  0x38 JR C, e 				- JUMP RELATIVE (CONDITIONAL)
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
 *  0xd0 RET NC 				- RETURN (CONDITIONAL)
 *  0xd2 JP NC, nn 				- JUMP (CONDTIONAL)
 *  0xd4 CALL NC, nn 			- CALL FUNCTION (CONDITIONAL)
 *  0xd7 RST 0x10				- RESTART / CALL FUNCTION (IMPLIED)
 *  0xd8 RET C 					- RETURN (CONDITIONAL)
 *  0xd9 RETI					- RETURN FROM INTERRUPT HANDLER
 *  0xda JP C, nn 				- JUMP (CONDITIONAL)
 *  0xdc CALL C, nn 			- CALL (CONDITIONAL)
 *  0xdf RST 0x18 				- RESTART / CALL FUNCTION (IMPLIED)
 *  0xe7 RST 0x20				- RESTART / CALL FUNCTION (IMPLIED)
 *  0xe9 JP HANDLER				- JUMP TO HL
 *  0xef RST 0x28 				- RESTART / CALL FUNCTION (IMPLIED)
 *  0xf7 RST 0x30 				- RESTART / CALL FUNCTION (IMPLIED)
 *  0xff RST 0x38 				- RESTART / CALL FUNCTION (IMPLIED)
 */

/* JR e - JUMP RELATIVE
 * Unconditional jump to the relative address specified by the signed 8-bit operand e
 */
void JUMPR(void)
{
	signed char e;

	e = (signed char)ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	PC_REGISTER = PC_REGISTER + e;
	/* 50% sure this handles overflow correctly, debug this to be sure */
}

/* JR NZ, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the NON-ZERO condition.
 */
void JUMPR_NZ(void)
{
	signed char e;

	e = (signed char)ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	/* If the Zero flag not set, add e to the PC */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0x7f)
	{
		PC_REGISTER = PC_REGISTER + e;
		/* 50% sure this handles overflow correctly, debug this to be sure */
	}
}

/* JR Z, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the ZERO condition.
 */
void JUMPR_Z(void)
{
	signed char e;

	e = (signed char)ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	/* If the Zero flag set, add e to the PC */
	if ((F_REGISTER | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		PC_REGISTER = PC_REGISTER + e;
		/* 50% sure this handles overflow correctly, debug this to be sure */
	}
}

/* JR NC, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the NO-CARRY condition.
 */
void JUMPR_NC(void)
{
	signed char e;

	e = (signed char)ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	/* If the Carry flag not set, add e to the PC */
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xef)
	{
		PC_REGISTER = PC_REGISTER + e;
		/* 50% sure this handles overflow correctly, debug this to be sure */
	}
}

/* JR C, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the CARRY condition.
 */
void JUMPR_C(void)
{
	signed char e;

	e = (signed char)ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	/* If the Carry flag set, add e to the PC */
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xff)
	{
		PC_REGISTER = PC_REGISTER + e;
		/* 50% sure this handles overflow correctly, debug this to be sure */
	}
}


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

/* RET NC - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the NO-CARRY condition.
 */
void RETURN_NC(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	/* If Carry Flag not set, set PC to new address specified by the Stack Pointer 
	 * See CALL instruction for how this return Address is stored */
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xef)
	{
		lsb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
		msb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1;
		addr = (unsigned short)(msb << 8) + (unsigned short)lsb;
		PC_REGISTER = addr;
	}
}

/* JP NC - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the NO-CARRY condition.
 */
void JUMP_NC(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	lsb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
	msb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1;
	addr = (unsigned short)(msb << 8) + (unsigned short)lsb;

	/* If Carry Flag not set, set PC to new address */
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xef)
	{
		PC_REGISTER = addr;
	}
}

/* CALL NC - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the NO-CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_NC(void)
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

	/* If Carry Flag not set, create the Return Address from the current PC, write it to SP, 
	 * then set the PC to the newly called function */
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xef)
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

/* RST 0x10 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x10.
 */
void RESTART_10(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0010 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0010;
}

/* RET C - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the CARRY condition.
 */
void RETURN_C(void)
{
	unsigned char lsb;
	unsigned char msb;
	unsigned short addr;

	/* If Zero Flag set, set PC to new address specified by the Stack Pointer 
	 * See CALL instruction for how this return Address is stored */
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xff)
	{
		lsb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1; /* increment by 1 because it's BYTE adressable, is it tho? */
		msb = ReadMemory(SP_REGISTER);
		SP_REGISTER = SP_REGISTER + 1;
		addr = (unsigned short)(msb << 8) + (unsigned short)lsb;
		PC_REGISTER = addr;
	}
}

/* RETI - RETURN FROM INTERRUPT HANDLER
 * Unconditional return from a function. Also enables interrupts by setting IME=1.
 */
void RETURN_IME(void)
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
	IME_FLAG = 1;
}

/* JP C - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void JUMP_C(void)
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
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xff)
	{
		PC_REGISTER = addr;
	}
}

/* CALL C - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_C(void)
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
	if ((F_REGISTER | (unsigned char)0xef) == (unsigned char)0xff)
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

/* RST 0x18 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x18.
 */
void RESTART_18(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0018 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0018;
}

/* RST 0x20 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x20.
 */
void RESTART_20(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0020 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0020;
}

/* JP HL - JUMP TO HL
 * Unconditional jump to the absolute address specified by the 16-bit register HL.
 */
void JUMP_HL(void)
{
	unsigned short addr;
	addr = (unsigned short)(H_REGISTER << 8) + (unsigned short)L_REGISTER;
	PC_REGISTER = addr;
}

/* RST 0x28 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x28.
 */
void RESTART_28(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0028 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0028;
}

/* RST 0x30 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x30.
 */
void RESTART_30(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0030 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0030;
}

/* RST 0x38 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x38.
 */
void RESTART_38(void)
{
	unsigned short addr;
	unsigned char tmp;

	/* Create return address from current PC, write it to SP. 
	 * Then set PC to 0x0038 */
	SP_REGISTER = SP_REGISTER - 1;
	tmp = PC_REGISTER >> 8;
	WriteMemory(SP_REGISTER, tmp);
	SP_REGISTER = SP_REGISTER - 1; 
	tmp = PC_REGISTER;
	WriteMemory(SP_REGISTER, tmp);
	PC_REGISTER = (unsigned short)0x0038;
}

