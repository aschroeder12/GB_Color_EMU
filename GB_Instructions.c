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
 *  0x76 HALT				- HALT SYSTEM CLOCK, look at gbdev.io
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
 * 	0x80 ADD B 				- ADD (REGISTER)
 * 	0x81 ADD C 				- ADD (REGISTER)
 * 	0x82 ADD D 				- ADD (REGISTER)
 * 	0x83 ADD E 				- ADD (REGISTER)
 * 	0x84 ADD H 				- ADD (REGISTER)
 * 	0x85 ADD L 				- ADD (REGISTER)
 * 	0x86 ADD (HL) 			- ADD (INDIRECT HL)
 * 	0x87 ADD A 				- ADD (REGISTER)
 * 	0x88 ADC B 				- ADD (REGISTER)
 * 	0x89 ADC C 				- ADD (REGISTER)
 * 	0x8a ADC D 				- ADD (REGISTER)
 * 	0x8b ADC E 				- ADD (REGISTER)
 * 	0x8c ADC H 				- ADD (REGISTER)
 * 	0x8d ADC L 				- ADD (REGISTER)
 * 	0x8e ADC (HL) 			- ADD (INDIRECT HL)
 * 	0x8f ADC A 				- ADD (REGISTER)
 * 
 * 
 *******************************************************/

#include"GB_Registers.h"

/*************************************************************************************************** 0x40 **/
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


/*************************************************************************************************** 0x50 **/
/** LD D, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register B.
 */
void LOAD_REGISTER_D_B()
{
	D_REGISTER = B_REGISTER;
}
/** LD D, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register C. 
 */
void LOAD_REGISTER_D_C()
{
	D_REGISTER = C_REGISTER;
}
/** LD D, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register D. 
 */
void LOAD_REGISTER_D_D()
{
	D_REGISTER = D_REGISTER;
}
/** LD D, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register E. 
 */
void LOAD_REGISTER_D_E()
{
	D_REGISTER = E_REGISTER;
}
/** LD D, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register H
 */
void LOAD_REGISTER_D_H()
{
	D_REGISTER = H_REGISTER;
}
/** LD D, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register L
 */
void LOAD_REGISTER_D_L()
{
	D_REGISTER = L_REGISTER;
}
/** LD D, HL - LOAD REGISTER (INDIRECT HL)
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
/** LD D, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register D, data from the 8-bit register A
 */
void LOAD_REGISTER_D_A()
{
	D_REGISTER = A_REGISTER;
}
/** LD E, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register B.
 */
void LOAD_REGISTER_E_B()
{
	E_REGISTER = B_REGISTER;
}
/** LD E, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register C.
 */
void LOAD_REGISTER_E_C()
{
	E_REGISTER = C_REGISTER;
}
/** LD E, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register D. 
 */
void LOAD_REGISTER_E_D()
{
	E_REGISTER = D_REGISTER;
}
/** LD E, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register E. 
 */
void LOAD_REGISTER_E_E()
{
	E_REGISTER = E_REGISTER;
}
/** LD E, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register H
 */
void LOAD_REGISTER_E_H()
{
	E_REGISTER = H_REGISTER;
}
/** LD E, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register L
 */
void LOAD_REGISTER_E_L()
{
	E_REGISTER = L_REGISTER;
}
/** LD E, HL - LOAD REGISTER (INDIRECT HL)
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
/** LD E, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register E, data from the 8-bit register A
 */
void LOAD_REGISTER_E_A()
{
	E_REGISTER = A_REGISTER;
}



/*************************************************************************************************** 0x60 **/
/** LD H, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register B.
 */
void LOAD_REGISTER_H_B()
{
	H_REGISTER = B_REGISTER;
}
/** LD H, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register C. 
 */
void LOAD_REGISTER_H_C()
{
	H_REGISTER = C_REGISTER;
}
/** LD H, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register D. 
 */
void LOAD_REGISTER_H_D()
{
	H_REGISTER = D_REGISTER;
}
/** LD H, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register E. 
 */
void LOAD_REGISTER_H_E()
{
	H_REGISTER = E_REGISTER;
}
/** LD H, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register H
 */
void LOAD_REGISTER_H_H()
{
	H_REGISTER = H_REGISTER;
}
/** LD H, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register L
 */
void LOAD_REGISTER_H_L()
{
	H_REGISTER = L_REGISTER;
}
/** LD H, HL - LOAD REGISTER (INDIRECT HL)
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
/** LD H, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register H, data from the 8-bit register A
 */
void LOAD_REGISTER_H_A()
{
	H_REGISTER = A_REGISTER;
}
/** LD L, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register B.
 */
void LOAD_REGISTER_L_B()
{
	L_REGISTER = B_REGISTER;
}
/** LD L, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register C.
 */
void LOAD_REGISTER_L_C()
{
	L_REGISTER = C_REGISTER;
}
/** LD L, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register D. 
 */
void LOAD_REGISTER_L_D()
{
	L_REGISTER = D_REGISTER;
}
/** LD L, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register E. 
 */
void LOAD_REGISTER_L_E()
{
	L_REGISTER = E_REGISTER;
}
/** LD L, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register H
 */
void LOAD_REGISTER_L_H()
{
	L_REGISTER = H_REGISTER;
}
/** LD L, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register L
 */
void LOAD_REGISTER_L_L()
{
	L_REGISTER = L_REGISTER;
}
/** LD L, HL - LOAD REGISTER (INDIRECT HL)
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
/** LD L, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register L, data from the 8-bit register A
 */
void LOAD_REGISTER_L_A()
{
	L_REGISTER = A_REGISTER;
}

/*************************************************************************************************** 0x70 **/
/** LD HL, B - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register B.
 */
void LOAD_REGISTER_HL_B()
{

	WriteMemory(HL_REGISTER, B_REGISTER);
}
/** LD HL, C - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register C. 
 */
void LOAD_REGISTER_HL_C()
{
	WriteMemory(HL_REGISTER, C_REGISTER);
}
/** LD HL, D - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register D. 
 */
void LOAD_REGISTER_HL_D()
{
	WriteMemory(HL_REGISTER, D_REGISTER);
}
/** LD HL, E - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register E. 
 */
void LOAD_REGISTER_HL_E()
{
	WriteMemory(HL_REGISTER, E_REGISTER);
}
/** LD HL, H - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register H
 */
void LOAD_REGISTER_HL_H()
{
	WriteMemory(HL_REGISTER, H_REGISTER);
}
/** LD HL, L - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register L
 */
void LOAD_REGISTER_HL_L()
{
	WriteMemory(HL_REGISTER, L_REGISTER);
}
/** HALT
 * Enter CPU low-power consumption mode until an interrupt occurs. 
 * The exact behavior of this instruction depends on the state of the IME flag.
 * 
 * IME set
 * 	- The CPU enters low-power mode until after an interrupt is about to be serviced. 
 * 	- The handler is executed normally, and the CPU resumes execution after the HALT when that returns.
 * 
 * IME not set
 * 	- The behavior depends on whether an interrupt is pending (i.e. ‘[IE] & [IF]’ is non-zero).
 * 		- None pending
 * 			As soon as an interrupt becomes pending, the CPU resumes execution. This is like the above, except that the handler is not called.
 * 		- Some pending
 * 			The CPU continues execution after the HALT, but the byte after it is read twice in a row (PC is not incremented, due to a hardware bug).
 * 
 */
void HALT()
{
	/*TODO*/
	/* If IME is set */
	if (IME_FLAG != 0)
	{
		while (IE_REGISTER & Interrupt_FLAG == 0)
		{
			/* Spin baby spin until there is a pending interrupt*/
			/* Call an "check for interrupts" function so we aren't stuck in an infinite loop?*/
		}

		/* Call interrupt handler */
	}
	else /* IME not set */
	{
		/* If no interrupt pending */
		if (IE_REGISTER & Interrupt_FLAG == 0)
		{
			while (IE_REGISTER & Interrupt_FLAG == 0)
			{
				/* Spin baby spin until there is a pending interrupt*/
				/* Call an "check for interrupts" function so we aren't stuck in an infinite loop?*/
			}
			/* Exit without calling an interrupt handler */
		}
		else /* there is an interrupt pending */
		{
			/* immediately exit, but due to halt bug the PC fails to be normally incremented */
		}
	}
}
/** LD HL, A - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register A
 */
void LOAD_REGISTER_HL_A()
{
	WriteMemory(HL_REGISTER, A_REGISTER);
}
/** LD A, B - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register B.
 */
void LOAD_REGISTER_A_B()
{
	A_REGISTER = B_REGISTER;
}
/** LD A, C - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register C.
 */
void LOAD_REGISTER_A_C()
{
	A_REGISTER = C_REGISTER;
}
/** LD A, D - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register D. 
 */
void LOAD_REGISTER_A_D()
{
	A_REGISTER = D_REGISTER;
}
/** LD A, E - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register E. 
 */
void LOAD_REGISTER_A_E()
{
	A_REGISTER = E_REGISTER;
}
/** LD A, H - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register H
 */
void LOAD_REGISTER_A_H()
{
	A_REGISTER = H_REGISTER;
}
/** LD A, L - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register L
 */
void LOAD_REGISTER_A_L()
{
	A_REGISTER = L_REGISTER;
}
/** LD A, HL - LOAD REGISTER (INDIRECT HL)
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
/** LD A, A - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register A, data from the 8-bit register A
 */
void LOAD_REGISTER_A_A()
{
	A_REGISTER = A_REGISTER;
}

/************************************************************************************************** 0x80 
 * ADD B - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register B, and stores the result back into the A register.
 */
void ADD_REGISTER_B()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + B_REGISTER;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/* ADD C - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register C, and stores the result back into the A register.
 */
void ADD_REGISTER_C()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + C_REGISTER;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/* ADD D - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register D, and stores the result back into the A register.
 */
void ADD_REGISTER_D()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + D_REGISTER;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/* ADD E - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register E, and stores the result back into the A register.
 */
void ADD_REGISTER_E()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + E_REGISTER;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/* ADD H - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register H, and stores the result back into the A register.
 */
void ADD_REGISTER_H()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + H_REGISTER;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/* ADD L - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register L, and stores the result back into the A register.
 */
void ADD_REGISTER_L()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + L_REGISTER;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/* ADD HL - ADD (INDIRECT HL)
 * Adds to the 8-bit A register, data from the absolute address specificed by the 16-bit register HL, 
 * and stores the result back into the A register.
 */
void ADD_REGISTER_HL()
{
	unsigned char result, carry_per_bit;
	ADDRESS_BUS = (unsigned short)(H_REGISTER << 8);
	ADDRESS_BUS = ADDRESS_BUS | L_REGISTER;
	/* Debug this ADDRESS to make sure it is correct */
	DATA_BUS = ReadMemory(ADDRESS_BUS);

	result, carry_per_bit = A_REGISTER + DATA_BUS;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/* ADD A - ADD (REGISTER)
 * Adds to the 8-bit A register, the 8-bit register A, and stores the result back into the A register.
 */
void ADD_REGISTER_A()
{
	unsigned char result, carry_per_bit;

	result, carry_per_bit = A_REGISTER + A_REGISTER;
	// debug the carry_per_bit to make sure it works
	A_REGISTER = result;
	/* Deal with zero flag, bit 7 of F_REGISTER */
	if (result == (unsigned char)0) 
	{
		F_REGISTER = F_REGISTER | ZERO_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER & ZERO_RESET;
	}
	/* Deal with subtraction flag (N), bit 6 of F_REGISTER */
	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	/* Deal with the half-carry flag (H), bit 5 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0xf7) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | HALFCARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | HALFCARRY_RESET;
	}
	/* Deal with the carry flag, bit 4 of F_REGISTER */
	if ((carry_per_bit | (unsigned char)0x7f) == (unsigned char)0xff)
	{
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		F_REGISTER = F_REGISTER | CARRY_RESET;
	}
}

/** LD r, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register r, the immediate data n
 */

void LOAD_REGISTER_I(unsigned char* R_DEST)
{
	*R_DEST = 
}