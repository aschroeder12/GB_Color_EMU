/*  GB MOVE DATA INSTRUCTIONS DONE!!!
 *
 *  0x02 LD BC, A 			- LOAD FROM ACCUMULATOR (INDIRECT BC)
 *  0x06 LD B, n 			- LOAD REGISTER (IMMEDIATE)
 *  0x0a LD A, (BC) 		- LOAD ACCUMULATOR (INDIRECT BC)
 *  0x0e LD C, n 			- LOAD REGISTER (IMMEDIATE)
 *  0x12 LD DE, A 			- LOAD FROM ACCUMULATOR (INDIRECT DE)
 *  0x16 LD D, n 			- LOAD REGISTER (IMMEDIATE)
 *  0x1a LD A, (DE) 		- LOAD ACCUMULATOR (INDIRECT DE)
 *  0x1e LD E, n 			- LOAD REGISTER (IMMEDIATE)
 *  0x22 LD HL+, A 			- LOAD FROM ACCUMULATOR (INDIRECT HL, INCREMENT)
 *  0x26 LD H, n 			- LOAD REGISTER (IMMEDIATE)
 *  0x2a LD A, (HL+) 		- LOAD ACCUMULATOR (INDIRECT HL, INCREMENT)
 *  0x2e LD L, n 			- LOAD REGISTER (IMMEDIATE)
 *  0x32 LD HL-, A 			- LOAD FROM ACCUMULATOR (INDIRECT HL, DECREMENT)
 *  0x36 LD (HL), n 		- LOAD REGISTER (IMMEDIATE)
 *  0x3a LD A, (HL-) 		- LOAD ACCUMULATOR (INDIRECT HL, DECREMENT)
 *  0x3e LD A, n 			- LOAD REGISTER (IMMEDIATE)

 *  0x40 LD B, B 			- LOAD REGISTER (REGISTER)
 *  0x41 LD B, C 			- LOAD REGISTER (REGISTER)
 *  0x42 LD B, D 			- LOAD REGISTER (REGISTER)
 *  0x43 LD B, E 			- LOAD REGISTER (REGISTER)
 *  0x44 LD B, H 			- LOAD REGISTER (REGISTER)
 *  0x45 LD B, L 			- LOAD REGISTER (REGISTER)
 *  0x46 LD B, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  0x47 LD B, A 			- LOAD REGISTER (REGISTER)
 *  0x48 LD C, B 			- LOAD REGISTER (REGISTER)
 *  0x49 LD C, C 			- LOAD REGISTER (REGISTER)
 *  0x4a LD C, D 			- LOAD REGISTER (REGISTER)
 *  0x4b LD C, E 			- LOAD REGISTER (REGISTER)
 *  0x4c LD C, H 			- LOAD REGISTER (REGISTER)
 *  0x4d LD C, L 			- LOAD REGISTER (REGISTER)
 *  0x4e LD C, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  0x4f LD C, A 			- LOAD REGISTER (REGISTER)
 * 
 *  0x50 LD D, B 			- LOAD REGISTER (REGISTER)
 *  0x51 LD D, C 			- LOAD REGISTER (REGISTER)
 *  0x52 LD D, D 			- LOAD REGISTER (REGISTER)
 *  0x53 LD D, E 			- LOAD REGISTER (REGISTER)
 *  0x54 LD D, H 			- LOAD REGISTER (REGISTER)
 *  0x55 LD D, L 			- LOAD REGISTER (REGISTER)
 *  0x56 LD D, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  0x57 LD D, A 			- LOAD REGISTER (REGISTER)
 *  0x58 LD E, B 			- LOAD REGISTER (REGISTER)
 *  0x59 LD E, C 			- LOAD REGISTER (REGISTER)
 *  0x5a LD E, D 			- LOAD REGISTER (REGISTER)
 *  0x5b LD E, E 			- LOAD REGISTER (REGISTER)
 *  0x5c LD E, H 			- LOAD REGISTER (REGISTER)
 *  0x5d LD E, L 			- LOAD REGISTER (REGISTER)
 *  0x5e LD E, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  0x5f LD E, A 			- LOAD REGISTER (REGISTER)
 * 
 *  0x60 LD H, B 			- LOAD REGISTER (REGISTER)
 *  0x61 LD H, C 			- LOAD REGISTER (REGISTER)
 *  0x62 LD H, D 			- LOAD REGISTER (REGISTER)
 *  0x63 LD H, E 			- LOAD REGISTER (REGISTER)
 *  0x64 LD H, H 			- LOAD REGISTER (REGISTER)
 *  0x65 LD H, L 			- LOAD REGISTER (REGISTER)
 *  0x66 LD H, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  0x67 LD H, A 			- LOAD REGISTER (REGISTER)
 *  0x68 LD L, B 			- LOAD REGISTER (REGISTER)
 *  0x69 LD L, C 			- LOAD REGISTER (REGISTER)
 *  0x6a LD L, D 			- LOAD REGISTER (REGISTER)
 *  0x6b LD L, E 			- LOAD REGISTER (REGISTER)
 *  0x6c LD L, H 			- LOAD REGISTER (REGISTER)
 *  0x6d LD L, L 			- LOAD REGISTER (REGISTER)
 *  0x6e LD L, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  0x6f LD L, A 			- LOAD REGISTER (REGISTER)
 * 
 *  0x70 LD HL, B 			- LOAD FROM REGISTER (INDIRECT HL)
 *  0x71 LD HL, C 			- LOAD FROM REGISTER (INDIRECT HL)
 *  0x72 LD HL, D 			- LOAD FROM REGISTER (INDIRECT HL)
 *  0x73 LD HL, E 			- LOAD FROM REGISTER (INDIRECT HL)
 *  0x74 LD HL, H 			- LOAD FROM REGISTER (INDIRECT HL)
 *  0x75 LD HL, L 			- LOAD FROM REGISTER (INDIRECT HL)
 *  0x77 LD HL, A 			- LOAD FROM REGISTER (INDIRECT HL)
 *  0x78 LD A, B 			- LOAD REGISTER (REGISTER)
 *  0x79 LD A, C 			- LOAD REGISTER (REGISTER)
 *  0x7a LD A, D 			- LOAD REGISTER (REGISTER)
 *  0x7b LD A, E 			- LOAD REGISTER (REGISTER)
 *  0x7c LD A, H 			- LOAD REGISTER (REGISTER)
 *  0x7d LD A, L 			- LOAD REGISTER (REGISTER)
 *  0x7e LD A, (HL) 		- LOAD REGISTER (INDIRECT HL)
 *  0x7f LD A, A 			- LOAD REGISTER (REGISTER)
 * 
 *  0xe0 LDH (n), A 		- LOAD FROM ACCUMLATOR (DIRECT)
 *  0xe2 LDH (C), A 		- LOAD FROM ACCUMLATOR (INDIRECT)
 *  0xea LDH (nn), A 		- LOAD FROM ACCUMLATOR (DIRECT)
 *  0xf0 LDH A, (n) 		- LOAD ACCUMLATOR (DIRECT)
 *  0xf2 LDH A, (C)			- LOAD ACCUMLATOR (INDIRECT)
 *  0xfa LDH A, (nn)		- LOAD ACCUMLATOR (DIRECT)
 *******************************************************/

#include"GB_Registers.h"

/* LD BC, A - LOAD FROM ACCUMULATOR (INDIRECT BC)
 * Load to the absolute address specified by the 16-bit register BC, data from the 8-bit A register
 */
void LOAD_REGISTER_BC_A(void)
{
	ADDRESS_BUS = (unsigned short)(B_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | C_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
}

/* LD B, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register B, the immediate data n.
 */
void LOAD_REGISTER_B_N(void)
{
	B_REGISTER = ReadMemory(PC_REGISTER);
}

/* LD A, (BC) - LOAD ACCUMULATOR (INDIRECT BC)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register BC
 */
void LOAD_REGISTER_A_BC(void)
{
	ADDRESS_BUS = (unsigned short)(B_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | C_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
}

/* LD C, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register C, the immediate data n.
 */
void LOAD_REGISTER_C_N(void)
{
	C_REGISTER = ReadMemory(PC_REGISTER);
}

/* LD DE, A - LOAD FROM ACCUMULATOR (INDIRECT DE)
 * Load to the absolute address specified by the 16-bit register DE, data from the 8-bit A register
 */
void LOAD_REGISTER_DE_A(void)
{
	ADDRESS_BUS = (unsigned short)(D_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | E_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
}

/* LD D, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register D, the immediate data n.
 */
void LOAD_REGISTER_B_N(void)
{
	D_REGISTER = ReadMemory(PC_REGISTER);
}

/* LD A, (DE) - LOAD ACCUMULATOR (INDIRECT DE)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register DE
 */
void LOAD_REGISTER_A_DE(void)
{
	ADDRESS_BUS = (unsigned short)(D_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | E_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
}

/* LD E, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register E, the immediate data n.
 */
void LOAD_REGISTER_E_N(void)
{
	E_REGISTER = ReadMemory(PC_REGISTER);
}

/* LD HL+, A - LOAD FROM ACCUMULATOR (INDIRECT HL, INCREMENT)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register.
 * The value of HL is incremented after the memory write
 */
void LOAD_REGISTER_HLI_A(void)
{
	unsigned short addr;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS, addr = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
	addr = addr + 1;
	H_REGISTER = addr >> 8;
	L_REGISTER = addr;
}

/* LD H, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register H, the immediate data n.
 */
void LOAD_REGISTER_H_N(void)
{
	H_REGISTER = ReadMemory(PC_REGISTER);
}

/* LD A, (HL+) - LOAD ACCUMULATOR (INDIRECT HL, INCREMENT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL.
 * The value of HL is incremented after the memory read.
 */
void LOAD_REGISTER_A_HLI(void)
{
	unsigned short addr;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS, addr = ADDRESS_BUS | L_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
	addr = addr + 1;
	H_REGISTER = addr >> 8;
	L_REGISTER = addr;
}

/* LD L, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register L, the immediate data n.
 */
void LOAD_REGISTER_L_N(void)
{
	L_REGISTER = ReadMemory(PC_REGISTER);
}

/* LD HL-, A - LOAD FROM ACCUMULATOR (INDIRECT HL, DECREMENT)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register.
 * The value of HL is decremented after the memory write
 */
void LOAD_REGISTER_HLD_A(void)
{
	unsigned short addr;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS, addr = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
	addr = addr - 1;
	H_REGISTER = addr >> 8;
	L_REGISTER = addr;
}

/* LD (HL), n - LOAD REGISTER (IMMEDIATE)
 * Load to the absolute address specified by the 16-bit register HL, the immediate data n
 */
void LOAD_REGISTER_HL_N(void)
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS, addr = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, ReadMemory(PC_REGISTER));
}

/* LD A, (HL-) - LOAD ACCUMULATOR (INDIRECT HL, DECREMENT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL.
 * The value of HL is decremented after the memory read.
 */
void LOAD_REGISTER_A_HLD(void)
{
	unsigned short addr;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS, addr = ADDRESS_BUS | L_REGISTER;
	A_REGISTER = ReadMemory(ADDRESS_BUS);
	addr = addr - 1;
	H_REGISTER = addr >> 8;
	L_REGISTER = addr;
}

/* LD A, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register A, the immediate data n.
 */
void LOAD_REGISTER_A_N(void)
{
	A_REGISTER = ReadMemory(PC_REGISTER);
}

/*************************************************************************************************** 0x40 **/
/* LD B, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register B. Why?
 */
void LOAD_REGISTER_B_B()
{
	B_REGISTER = B_REGISTER;
}
/* LD B, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register C. 
 */
void LOAD_REGISTER_B_C()
{
	B_REGISTER = C_REGISTER;
}
/* LD B, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register D. 
 */
void LOAD_REGISTER_B_D()
{
	B_REGISTER = D_REGISTER;
}
/* LD B, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register E. 
 */
void LOAD_REGISTER_B_E()
{
	B_REGISTER = E_REGISTER;
}
/* LD B, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register H
 */
void LOAD_REGISTER_B_H()
{
	B_REGISTER = H_REGISTER;
}
/* LD B, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register L
 */
void LOAD_REGISTER_B_L()
{
	B_REGISTER = L_REGISTER;
}
/* LD B, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register B, data from the absolute address
 * specified by the 16-bit register HL
 */
void LOAD_REGISTER_B_HL()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	B_REGISTER = DATA_BUS;
}
/* LD B, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register A
 */
void LOAD_REGISTER_B_A()
{
	B_REGISTER = A_REGISTER;
}
/* LD C, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register B.
 */
void LOAD_REGISTER_C_B()
{
	C_REGISTER = B_REGISTER;
}
/* LD C, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register C. Why? 
 */
void LOAD_REGISTER_C_C()
{
	C_REGISTER = C_REGISTER;
}
/* LD C, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register D. 
 */
void LOAD_REGISTER_C_D()
{
	C_REGISTER = D_REGISTER;
}
/* LD C, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register E. 
 */
void LOAD_REGISTER_C_E()
{
	C_REGISTER = E_REGISTER;
}
/* LD C, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register H
 */
void LOAD_REGISTER_C_H()
{
	C_REGISTER = H_REGISTER;
}
/* LD C, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register L
 */
void LOAD_REGISTER_C_L()
{
	C_REGISTER = L_REGISTER;
}
/* LD C, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register C, data from the absolute address
 * specified by the 16-bit register HL
 */
void LOAD_REGISTER_C_HL()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	C_REGISTER = DATA_BUS;
}
/* LD C, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register A
 */
void LOAD_REGISTER_C_A()
{
	C_REGISTER = A_REGISTER;
}


/************************************************************************************************** 0x50 **/
/* LD D, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register B.
 */
void LOAD_REGISTER_D_B()
{
	D_REGISTER = B_REGISTER;
}
/* LD D, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register C. 
 */
void LOAD_REGISTER_D_C()
{
	D_REGISTER = C_REGISTER;
}
/* LD D, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register D. 
 */
void LOAD_REGISTER_D_D()
{
	D_REGISTER = D_REGISTER;
}
/* LD D, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register E. 
 */
void LOAD_REGISTER_D_E()
{
	D_REGISTER = E_REGISTER;
}
/* LD D, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register H
 */
void LOAD_REGISTER_D_H()
{
	D_REGISTER = H_REGISTER;
}
/* LD D, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register L
 */
void LOAD_REGISTER_D_L()
{
	D_REGISTER = L_REGISTER;
}
/* LD D, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register D, data from the absolute address
 * specified by the 16-bit register HL
 */
void LOAD_REGISTER_D_HL()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	D_REGISTER = DATA_BUS;
}
/* LD D, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register A
 */
void LOAD_REGISTER_D_A()
{
	D_REGISTER = A_REGISTER;
}
/* LD E, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register B.
 */
void LOAD_REGISTER_E_B()
{
	E_REGISTER = B_REGISTER;
}
/* LD E, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register C.
 */
void LOAD_REGISTER_E_C()
{
	E_REGISTER = C_REGISTER;
}
/* LD E, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register D. 
 */
void LOAD_REGISTER_E_D()
{
	E_REGISTER = D_REGISTER;
}
/* LD E, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register E. 
 */
void LOAD_REGISTER_E_E()
{
	E_REGISTER = E_REGISTER;
}
/* LD E, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register H
 */
void LOAD_REGISTER_E_H()
{
	E_REGISTER = H_REGISTER;
}
/* LD E, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register L
 */
void LOAD_REGISTER_E_L()
{
	E_REGISTER = L_REGISTER;
}
/* LD E, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register E, data from the absolute address
 * specified by the 16-bit register HL
 */
void LOAD_REGISTER_E_HL()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	E_REGISTER = DATA_BUS;
}
/* LD E, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register A
 */
void LOAD_REGISTER_E_A()
{
	E_REGISTER = A_REGISTER;
}



/*************************************************************************************************** 0x60 **/
/* LD H, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register B.
 */
void LOAD_REGISTER_H_B()
{
	H_REGISTER = B_REGISTER;
}
/* LD H, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register C. 
 */
void LOAD_REGISTER_H_C()
{
	H_REGISTER = C_REGISTER;
}
/* LD H, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register D. 
 */
void LOAD_REGISTER_H_D()
{
	H_REGISTER = D_REGISTER;
}
/* LD H, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register E. 
 */
void LOAD_REGISTER_H_E()
{
	H_REGISTER = E_REGISTER;
}
/* LD H, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register H
 */
void LOAD_REGISTER_H_H()
{
	H_REGISTER = H_REGISTER;
}
/* LD H, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register L
 */
void LOAD_REGISTER_H_L()
{
	H_REGISTER = L_REGISTER;
}
/* LD H, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register H, data from the absolute address
 * specified by the 16-bit register HL
 */
void LOAD_REGISTER_H_HL()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	H_REGISTER = DATA_BUS;
}
/* LD H, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register A
 */
void LOAD_REGISTER_H_A()
{
	H_REGISTER = A_REGISTER;
}
/* LD L, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register B.
 */
void LOAD_REGISTER_L_B()
{
	L_REGISTER = B_REGISTER;
}
/* LD L, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register C.
 */
void LOAD_REGISTER_L_C()
{
	L_REGISTER = C_REGISTER;
}
/* LD L, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register D. 
 */
void LOAD_REGISTER_L_D()
{
	L_REGISTER = D_REGISTER;
}
/* LD L, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register E. 
 */
void LOAD_REGISTER_L_E()
{
	L_REGISTER = E_REGISTER;
}
/* LD L, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register H
 */
void LOAD_REGISTER_L_H()
{
	L_REGISTER = H_REGISTER;
}
/* LD L, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register L
 */
void LOAD_REGISTER_L_L()
{
	L_REGISTER = L_REGISTER;
}
/* LD L, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register L, data from the absolute address
 * specified by the 16-bit register HL
 */
void LOAD_REGISTER_L_HL()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	L_REGISTER = DATA_BUS;
}
/* LD L, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register A
 */
void LOAD_REGISTER_L_A()
{
	L_REGISTER = A_REGISTER;
}

/*************************************************************************************************** 0x70 **/
/* LD HL, B - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register B.
 */
void LOAD_REGISTER_HL_B()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, B_REGISTER);
}
/* LD HL, C - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register C. 
 */
void LOAD_REGISTER_HL_C()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, C_REGISTER);
}
/* LD HL, D - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register D. 
 */
void LOAD_REGISTER_HL_D()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, D_REGISTER);
}
/* LD HL, E - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register E. 
 */
void LOAD_REGISTER_HL_E()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, E_REGISTER);
}
/* LD HL, H - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register H
 */
void LOAD_REGISTER_HL_H()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, H_REGISTER);
}
/* LD HL, L - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register L
 */
void LOAD_REGISTER_HL_L()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, L_REGISTER);
}
/* LD HL, A - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register A
 */
void LOAD_REGISTER_HL_A()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	WriteMemory(ADDRESS_BUS, A_REGISTER);
}
/* LD A, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register B.
 */
void LOAD_REGISTER_A_B()
{
	A_REGISTER = B_REGISTER;
}
/* LD A, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register C.
 */
void LOAD_REGISTER_A_C()
{
	A_REGISTER = C_REGISTER;
}
/* LD A, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register D. 
 */
void LOAD_REGISTER_A_D()
{
	A_REGISTER = D_REGISTER;
}
/* LD A, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register E. 
 */
void LOAD_REGISTER_A_E()
{
	A_REGISTER = E_REGISTER;
}
/* LD A, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register H
 */
void LOAD_REGISTER_A_H()
{
	A_REGISTER = H_REGISTER;
}
/* LD A, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register L
 */
void LOAD_REGISTER_A_L()
{
	A_REGISTER = L_REGISTER;
}
/* LD A, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register A, data from the absolute address
 * specified by the 16-bit register HL
 */
void LOAD_REGISTER_A_HL()
{
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);
	A_REGISTER = DATA_BUS;
}
/* LD A, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register A
 */
void LOAD_REGISTER_A_A()
{
	A_REGISTER = A_REGISTER;
}

/* LDH (n), A - LOAD FROM ACCUMULATOR (DIRECT)
 * Load to the address specified by the 8-bit immediate data n, data from the 8-bit A register. The
 * full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the
 * least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 */
void LOAD_HW_N_A(void)
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
void LOAD_HW_C_A(void)
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
void LOAD_HW_NN_A(void)
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
void LOAD_HW_A_N(void)
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
void LOAD_HW_A_C(void)
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
void LOAD_HW_A_NN(void)
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
