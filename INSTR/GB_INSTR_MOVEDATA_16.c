/* GB 16-BIT MOVE DATA INSTRUCTIONS DONE!!
 * LOAD POP PUSH
 */
#include "../MEM/GB_MEM.h"
#include "../LIB/GB_LIB.h"
#include "GB_INSTR_MOVEDATA_16.h"

/* LD RR, nn - LOAD 16-BIT REGISTER (IMMEDIATE)
 * Load to the 16-bit register RR, the immediate 16-bit data nn.
 * MSB is R1, LSB is R2!
 */
void INSTR_LOAD_REGISTER_RR_NN(unsigned char *R1, unsigned char *R2)
{
	unsigned char lsb, msb;
	unsigned short data;
	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	data = (unsigned short)(msb << 8) + (unsigned short)lsb;
	*R1 = data >> 8;
	*R2 = data;
}

/* LD SP, nn - LOAD 16-BIT REGISTER (IMMEDIATE)
 * Load to the 16-bit SP register, the immediate 16-bit data nn.
 */
void INSTR_LOAD_REGISTER_SP_NN(void)
{
	unsigned char lsb, msb;
	unsigned short data;
	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	data = (unsigned short)(msb << 8) + (unsigned short)lsb;
	SP_REGISTER = data;
}

/* LD nn, SP - LOAD FROM SP (IMMEDIATE)
 * Load to the absolute address specified by the 16-bit operand nn, data from the 16-bit SP register.
 * Yeah it's not technically "Load register", oh well
 */
void INSTR_LOAD_REGISTER_NN_SP(void)
{
	unsigned char lsb, msb;
	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	ADDRESS_BUS = (unsigned short)(msb << 8) + (unsigned short)lsb;
	msb = SP_REGISTER >> 8;
	lsb = SP_REGISTER;
	WriteMemory(ADDRESS_BUS, lsb);
	ADDRESS_BUS = ADDRESS_BUS + 1;
	WriteMemory(ADDRESS_BUS, msb);
}

/* POP RR - POP FROM STACK
 * Pops to the 16-bit register rr, data from the stack memory.
 * This instruction does not do calculations that affect flags, but POP AF completely replaces the
 * F register value, so all flags are changed based on the 8-bit data that is read from memory.
 */
void INSTR_POP_RR(unsigned char *R1, unsigned char *R2)
{
	unsigned char lsb, msb;
	unsigned short data;
	lsb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1;
	msb = ReadMemory(SP_REGISTER);
	SP_REGISTER = SP_REGISTER + 1;
	data = (unsigned short)(msb << 8) + (unsigned short)lsb;
	*R1 = data >> 8;
	*R2 = data;
	/* yeah probably didn't need "data", but oh well it's good practice */
}

/* PUSH RR - PUSH TO STACK
 * Push to the stack memory, data from the 16-bit register RR
 */
void INSTR_PUSH_RR(unsigned char *R1, unsigned char *R2)
{
	SP_REGISTER = SP_REGISTER - 1;
	WriteMemory(SP_REGISTER, *R1);
	SP_REGISTER = SP_REGISTER - 1;
	WriteMemory(SP_REGISTER, *R2);
}

/* LD SP, HL - LOAD SP FROM HL
 * Load to the 16-bit SP register, data from the 16-bit HL register.
 */
void INSTR_LOAD_REGISTER_SP_HL(void)
{
	unsigned short data;
	data = (unsigned short)(H_REGISTER << 8) + (unsigned short)L_REGISTER;
	SP_REGISTER = data;
}

/* LD HL, SP+e - LOAD HL FROM ADJUSTED SP
 * Load to the HL register, 16-bit data calculated by adding the signed 8-bit operand e to the 16-
 * bit value of the SP register.
 */
void INSTR_LOAD_REGISTER_HL_ADJSP(void)
{
	unsigned short result;
	signed char e;
	e = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	result = SP_REGISTER + e; /* hopefully this converts correctly to unsigned short? */
	H_REGISTER = result >> 8;
	L_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	F_REGISTER = F_REGISTER & ZERO_RESET;
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((result | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((result | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
}

