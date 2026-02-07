/*  GB 8-BIT MOVE DATA INSTRUCTIONS DONE!!!
 *
 *  0x02 LD BC, A 			- LOAD FROM ACCUMULATOR (INDIRECT BC)
 *  various LD R, n 		- LOAD REGISTER (IMMEDIATE)
 *  0x0a LD A, (BC) 		- LOAD ACCUMULATOR (INDIRECT BC)
 *  0x12 LD DE, A 			- LOAD FROM ACCUMULATOR (INDIRECT DE)
 *  0x1a LD A, (DE) 		- LOAD ACCUMULATOR (INDIRECT DE)
 *  0x22 LD HL+, A 			- LOAD FROM ACCUMULATOR (INDIRECT HL, INCREMENT)
 *  0x2a LD A, (HL+) 		- LOAD ACCUMULATOR (INDIRECT HL, INCREMENT)
 *  0x32 LD HL-, A 			- LOAD FROM ACCUMULATOR (INDIRECT HL, DECREMENT)
 *  0x36 LD (HL), n 		- LOAD REGISTER (IMMEDIATE)
 *  0x3a LD A, (HL-) 		- LOAD ACCUMULATOR (INDIRECT HL, DECREMENT)

 *  various LD R, r 		- LOAD REGISTER (REGISTER)
 *  various LD R, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  various LD HL, R 		- LOAD FROM REGISTER (INDIRECT HL)
 * 
 *  0xe0 LDH (n), A 		- LOAD FROM ACCUMLATOR (DIRECT)
 *  0xe2 LDH (C), A 		- LOAD FROM ACCUMLATOR (INDIRECT)
 *  0xea LDH (nn), A 		- LOAD FROM ACCUMLATOR (DIRECT)
 *  0xf0 LDH A, (n) 		- LOAD ACCUMLATOR (DIRECT)
 *  0xf2 LDH A, (C)			- LOAD ACCUMLATOR (INDIRECT)
 *  0xfa LDH A, (nn)		- LOAD ACCUMLATOR (DIRECT)
 *******************************************************/

#include "../MEM/GB_MEM.h"
#include "../LIB/GB_LIB.h"
#include "GB_INSTR_MOVEDATA_8.h"

/* LD BC, A - LOAD FROM ACCUMULATOR (INDIRECT BC)
 * Load to the absolute address specified by the 16-bit register BC, data from the 8-bit A register
 */
void INSTR_LOAD_REGISTER_BC_A(void)
{
	ADDRESS_BUS = (unsigned short)(B_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | C_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
}

/* LD B, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register R, the immediate data n.
 */
void INSTR_LOAD_REGISTER_R_N(unsigned char *R)
{
	*R = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
}

/* LD A, (BC) - LOAD ACCUMULATOR (INDIRECT BC)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register BC
 */
void INSTR_LOAD_REGISTER_A_BC(void)
{
	ADDRESS_BUS = (unsigned short)(B_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | C_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
}

/* LD DE, A - LOAD FROM ACCUMULATOR (INDIRECT DE)
 * Load to the absolute address specified by the 16-bit register DE, data from the 8-bit A register
 */
void INSTR_LOAD_REGISTER_DE_A(void)
{
	ADDRESS_BUS = (unsigned short)(D_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | E_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
}

/* LD A, (DE) - LOAD ACCUMULATOR (INDIRECT DE)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register DE
 */
void INSTR_LOAD_REGISTER_A_DE(void)
{
	ADDRESS_BUS = (unsigned short)(D_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | E_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
}

/* LD HL+, A - LOAD FROM ACCUMULATOR (INDIRECT HL, INCREMENT)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register.
 * The value of HL is incremented after the memory write
 */
void INSTR_LOAD_REGISTER_HLI_A(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
	ADDRESS_BUS = ADDRESS_BUS + 1;
	H_REGISTER = ADDRESS_BUS >> 8;
	L_REGISTER = ADDRESS_BUS;
}

/* LD A, (HL+) - LOAD ACCUMULATOR (INDIRECT HL, INCREMENT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL.
 * The value of HL is incremented after the memory read.
 */
void INSTR_LOAD_REGISTER_A_HLI(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS= ADDRESS_BUS | L_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
	ADDRESS_BUS = ADDRESS_BUS + 1;
	H_REGISTER = ADDRESS_BUS >> 8;
	L_REGISTER = ADDRESS_BUS;
}

/* LD HL-, A - LOAD FROM ACCUMULATOR (INDIRECT HL, DECREMENT)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register.
 * The value of HL is decremented after the memory write
 */
void INSTR_LOAD_REGISTER_HLD_A(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
	ADDRESS_BUS = ADDRESS_BUS - 1;
	H_REGISTER = ADDRESS_BUS >> 8;
	L_REGISTER = ADDRESS_BUS;
}

/* LD (HL), n - LOAD REGISTER (IMMEDIATE)
 * Load to the absolute address specified by the 16-bit register HL, the immediate data n
 */
void INSTR_LOAD_REGISTER_HL_N(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, ReadMemory(PC_REGISTER));
}

/* LD A, (HL-) - LOAD ACCUMULATOR (INDIRECT HL, DECREMENT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL.
 * The value of HL is decremented after the memory read.
 */
void INSTR_LOAD_REGISTER_A_HLD(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
	ADDRESS_BUS = ADDRESS_BUS - 1;
	H_REGISTER = ADDRESS_BUS >> 8;
	L_REGISTER = ADDRESS_BUS;
}

/* LD R, r - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register R, data from the 8-bit register r.
 */
void INSTR_LOAD_REGISTER_R_r(unsigned char *R, unsigned char *r)
{
	*R = *r;
}
/* LD R, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register R, data from the absolute address
 * specified by the 16-bit register HL
 */
void INSTR_LOAD_REGISTER_R_HL(unsigned char *R)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	*R = DATA_BUS;
}

/* LD HL, R - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register R.
 */
void INSTR_LOAD_REGISTER_HL_R(unsigned char *R)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, *R);
}

/* LDH (n), A - LOAD FROM ACCUMULATOR (DIRECT)
 * Load to the address specified by the 8-bit immediate data n, data from the 8-bit A register. The
 * full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the
 * least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_N_A(void)
{
	unsigned char lsb, msb;
	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	msb = 0xff;
	ADDRESS_BUS = (unsigned short)(msb << 8) + (unsigned short)lsb;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
	/* Should I be using the ADDRESS_BUS for all memory writes/reads??*/
}

/* LDH (C), A - LOAD FROM ACCUMULATOR (INDIRECT)
 * Load to the address specified by the 8-bit C register, data from the 8-bit A register. The full
 * 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the least
 * significant byte to the value of C, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_C_A(void)
{
	unsigned char lsb, msb;
	lsb = C_REGISTER;
	msb = 0xff;
	ADDRESS_BUS = (unsigned short)(msb << 8) + (unsigned short)lsb;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
	/* Should I be using the ADDRESS_BUS for all memory writes/reads??*/
}

/* LDH (nn), A - LOAD FROM ACCUMULATOR (DIRECT)
 * Load to the address specified by the 16-bit immediate data nn, data from the 8-bit A register.
 */
void INSTR_LOAD_HW_NN_A(void)
{
	unsigned char lsb, msb;
	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	ADDRESS_BUS = (unsigned short)(msb << 8) + (unsigned short)lsb;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
	/* Should I be using the ADDRESS_BUS for all memory writes/reads??*/
}

/* LDH A, (n) - LOAD ACCUMULATOR (DIRECT)
 * Load to the 8-bit A register, data from the address specified by the 8-bit immediate data n. The
 * full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the
 * least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_A_N(void)
{
	unsigned char lsb, msb;
	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	msb = 0xff;
	ADDRESS_BUS = (unsigned short)(msb << 8) + (unsigned short)lsb;
	A_REGISTER =  ReadMemory(ADDRESS_BUS);
	/* Should I be using the ADDRESS_BUS for all memory writes/reads??*/
}

/* LDH A, (C) - LOAD ACCUMULATOR (DIRECT)
 * Load to the 8-bit A register, data from the address specified by the 8-bit C register. The
 * full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the
 * least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_A_C(void)
{
	unsigned char lsb, msb;
	lsb = C_REGISTER;
	msb = 0xff;
	ADDRESS_BUS = (unsigned short)(msb << 8) + (unsigned short)lsb;
	A_REGISTER =  ReadMemory(ADDRESS_BUS);
	/* Should I be using the ADDRESS_BUS for all memory writes/reads??*/
}

/* LDH A, (nn) - LOAD ACCUMULATOR (DIRECT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit operand nn.
 */
void INSTR_LOAD_HW_A_NN(void)
{
	unsigned char lsb, msb;
	lsb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	msb = ReadMemory(PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;
	ADDRESS_BUS = (unsigned short)(msb << 8) + (unsigned short)lsb;
	A_REGISTER =  ReadMemory(ADDRESS_BUS);
	/* Should I be using the ADDRESS_BUS for all memory writes/reads??*/
}
