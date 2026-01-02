#ifndef INCLUDE_GB_INSTR_MISC_H
#define INCLUDE_GB_INSTR_MISC_H
/* NOP - NO OPERATION
 * No operation. This instruction doesn’t do anything, but can be used to add a delay of one
 * machine cycle and increment PC by one.
 */
void INSTR_NO_OPERATION(void);

/* STOP - STOP
 * Enter CPU very low power mode. Also used to switch between GBC double speed and normal speed CPU modes.
 * NOTE: No Licensed ROM uses the STOP instruction outside of CGB speed switching. 
 * This instruction is hella confusing and messed up, so I'm gonna skip it until I need to do it for GBC
 */
void INSTR_STOP(void);

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
void INSTR_HALT(void);

/* DI - DISABLE INTERRUPTS
 * Disables interrupt handling by setting IME=0 and cancelling any scheduled effects of the EI
 * instruction if any.
 */
void INSTR_DISABLE_INTERRUPTS(void);

/* EI - ENABLE INTERRUPTS
 * Schedules interrupt handling to be enabled after the next machine cycle.
 */
void INSTR_DISABLE_INTERRUPTS(void);

#endif