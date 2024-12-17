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
 * 
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
 * specified by the 16-bit register H
 */
void LOAD_REGISTER_B_HL()
{
	DATA_BUS = ReadMemory(ADDRESS_BUS = )
	B_REGISTER = H_REGISTER;
}




/** LD r, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register r, the immediate data n
 */

void LOAD_REGISTER_I(unsigned char* R_DEST)
{
	*R_DEST = 
}