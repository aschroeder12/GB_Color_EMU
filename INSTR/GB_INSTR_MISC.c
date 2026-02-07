/*  GB MISC INSTRUCTIONS TODO
 * 
 *  0x00 NOP 					- NO OPERATION
 *  0x10 STOP 					- STOP
 *  0x17 RLA					- ROTATE LEFT (ACCUMULATOR)
 *  0x76 HALT 					- HALT SYSTEM CLOCK
 *  0xf3 DI						- DISABLE INTERRUPTS
 *  0xfb EI 					- ENABLE INTERRUPTS
 * 
 */ 

#include "../MEM/GB_MEM.h"
#include "../LIB/GB_LIB.h"
#include "GB_INSTR_MISC.h"

/* NOP - NO OPERATION
 * No operation. This instruction doesn’t do anything, but can be used to add a delay of one
 * machine cycle and increment PC by one.
 */
void INSTR_NO_OPERATION(void)
{
	// do nothing
}

/* STOP - STOP
 * Enter CPU very low power mode. Also used to switch between GBC double speed and normal speed CPU modes.
 * NOTE: No Licensed ROM uses the STOP instruction outside of CGB speed switching. 
 * This instruction is hella confusing and messed up, so I'm gonna skip it until I need to do it for GBC
 */
void INSTR_STOP(void)
{
	PrintLog("STOP INSTRUCTION DETECTED, WTFFFFF\n");
	PrintLog("Trying to switch speeds for the GameBoy Color??\n");
}

/* RLA - ROTATE LEFT (ACCUMULATOR)
 * Rotates the 8-bit A register value left through the carry flag.
 * Every bit is shifted to the left (e.g. bit 1 value is copied from bit 0). The carry flag is copied to bit
 * 0, and bit 7 is copied to the carry flag. Note that unlike the related RL r instruction, RLA always
 * sets the zero flag to 0 without looking at the resulting value of the calculation
 */
void INSTR_RLA(unsigned char *R) /* just pass in A_REGISTER ptr */
{
	/* Scootch bit 7 into carry flag */
	if ((*R | ZERO_RESET) == (unsigned char)0xff)
	{
		*R = *R << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if ((F_REGISTER | CARRY_RESET) == (unsigned char)0xff)
		{
			*R = *R | 0x01;
		}
		F_REGISTER = F_REGISTER | CARRY_SET;
	}
	else
	{
		*R = *R << 1;
		/* Wrap carry flag into bit 0, it'll be 0 otherwise */
		if ((F_REGISTER | CARRY_RESET) == (unsigned char)0xff)
		{
			*R = *R | 0x01;
		}
		F_REGISTER = F_REGISTER & CARRY_RESET;
	}
	
	F_REGISTER = F_REGISTER & ZERO_RESET;

	F_REGISTER = F_REGISTER & SUBTRACTION_RESET;
	F_REGISTER = F_REGISTER & HALFCARRY_RESET;
}

/* HALT
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
 * TODO
 */
void INSTR_HALT()
{
	/*TODO*/
	/* If IME is set (Enables interrupt handling)*/
	if (IME_FLAG != 0)
	{
		while ((IE_REGISTER & INTERRUPT_FLAG) == 0)
		{
			/* Spin baby spin until there is a pending interrupt*/
			/* Call an "check for interrupts" function so we aren't stuck in an infinite loop?*/
			/* Once you program how the interrupts are handled, you can add a function call for that here */
		}

		/* Call interrupt handler */
	}
	else /* IME not set */
	{
		/* If no interrupt pending */
		if ((IE_REGISTER & INTERRUPT_FLAG) == 0)
		{
			while ((IE_REGISTER & INTERRUPT_FLAG) == 0)
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

/* DI - DISABLE INTERRUPTS
 * Disables interrupt handling by setting IME=0 and cancelling any scheduled effects of the EI
 * instruction if any.
 */
void INSTR_DISABLE_INTERRUPTS(void)
{
	IME_FLAG = (unsigned char)0;
}

/* EI - ENABLE INTERRUPTS
 * Schedules interrupt handling to be enabled after the next machine cycle.
 */
void INSTR_ENABLE_INTERRUPTS(void)
{
	IME_FLAG = (unsigned char)1; /* Not sure this is right, might need to do more here? */
}


