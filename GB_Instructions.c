/******************GB INSTRUCTION SET *****************
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
 * 
 * 
 * 
 * 
 *******************************************************/

#include"GB_Registers.h"

/** LD B, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register B. Why?
 */
void LOAD_REGISTER_B_B()
{
	B_REGISTER = B_REGISTER;
}
/** LD B, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register C. 
 */
void LOAD_REGISTER_B_C()
{
	B_REGISTER = C_REGISTER;
}
/** LD B, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register D. 
 */
void LOAD_REGISTER_B_D()
{
	B_REGISTER = D_REGISTER;
}
/** LD B, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register E. 
 */
void LOAD_REGISTER_B_E()
{
	B_REGISTER = E_REGISTER;
}
/** LD B, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register H
 */
void LOAD_REGISTER_B_H()
{
	B_REGISTER = H_REGISTER;
}
/** LD B, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register L
 */
void LOAD_REGISTER_B_L()
{
	B_REGISTER = L_REGISTER;
}
/** LD B, HL - LOAD REGISTER (INDIRECT HL)
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
/** LD B, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register B, data from the 8-bit register A
 */
void LOAD_REGISTER_B_A()
{
	B_REGISTER = A_REGISTER;
}


/** LD C, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register B.
 */
void LOAD_REGISTER_C_B()
{
	C_REGISTER = B_REGISTER;
}
/** LD C, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register C. Why? 
 */
void LOAD_REGISTER_C_C()
{
	C_REGISTER = C_REGISTER;
}
/** LD C, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register D. 
 */
void LOAD_REGISTER_C_D()
{
	C_REGISTER = D_REGISTER;
}
/** LD C, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register E. 
 */
void LOAD_REGISTER_C_E()
{
	C_REGISTER = E_REGISTER;
}
/** LD C, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register H
 */
void LOAD_REGISTER_C_H()
{
	C_REGISTER = H_REGISTER;
}
/** LD C, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register L
 */
void LOAD_REGISTER_C_L()
{
	C_REGISTER = L_REGISTER;
}
/** LD C, HL - LOAD REGISTER (INDIRECT HL)
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
/** LD C, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register C, data from the 8-bit register A
 */
void LOAD_REGISTER_C_A()
{
	C_REGISTER = A_REGISTER;
}



/** LD r, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register r, the immediate data n
 */

void LOAD_REGISTER_I(unsigned char* R_DEST)
{
	*R_DEST = 
}