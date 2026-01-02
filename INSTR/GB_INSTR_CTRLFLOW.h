#ifndef INCLUDE_GB_INSTR_CTRLFLOW_H
#define INCLUDE_GB_INSTR_CTRLFLOW_H
/* JR e - JUMP RELATIVE
 * Unconditional jump to the relative address specified by the signed 8-bit operand e
 */
void INSTR_JUMPR(void);

/* JR NZ, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the NON-ZERO condition.
 */
void INSTR_JUMPR_NZ(void);

/* JR Z, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the ZERO condition.
 */
void INSTR_JUMPR_Z(void);

/* JR NC, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the NO-CARRY condition.
 */
void INSTR_JUMPR_NC(void);

/* JR C, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the CARRY condition.
 */
void INSTR_JUMPR_C(void);

/* RET NZ - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the NON-ZERO condition.
 */
void INSTR_RETURN_NZ(void);

/* JP NZ - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the NON-ZERO condition.
 */
void INSTR_JUMP_NZ(void);

/* JP - JUMP
 * Unconditional jump to the absolute address specified by the 16-bit immediate operand.
 */
void INSTR_JUMP(void);

/* CALL NZ - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the NON-ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void INSTR_CALL_NZ(void);

/* RST 0x00 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x00.
 */
void INSTR_RESTART_00(void);

/* RET Z - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the ZERO condition.
 */
void INSTR_RETURN_Z(void);

/* RET - RETURN 
 * Unconditional return from a function
 */
void INSTR_RETURN(void);

/* JP Z - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void INSTR_JUMP_Z(void);

/* CALL Z - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void INSTR_CALL_Z(void);

/* CALL - CALL FUNCTION
 * Unconditional function call to the absolute address specified by the 16-bit operand.
 */
void INSTR_CALL(void);

/* RST 0x08 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x08.
 */
void INSTR_RESTART_08(void);

/* RET NC - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the NO-CARRY condition.
 */
void INSTR_RETURN_NC(void);

/* JP NC - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the NO-CARRY condition.
 */
void INSTR_JUMP_NC(void);

/* CALL NC - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the NO-CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void INSTR_CALL_NC(void);

/* RST 0x10 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x10.
 */
void INSTR_RESTART_10(void);

/* RET C - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the CARRY condition.
 */
void INSTR_RETURN_C(void);

/* RETI - RETURN FROM INTERRUPT HANDLER
 * Unconditional return from a function. Also enables interrupts by setting IME=1.
 */
void INSTR_RETURN_IME(void);

/* JP C - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void INSTR_JUMP_C(void);

/* CALL C - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void INSTR_CALL_C(void);

/* RST 0x18 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x18.
 */
void INSTR_RESTART_18(void);

/* RST 0x20 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x20.
 */
void INSTR_RESTART_20(void);

/* JP HL - JUMP TO HL
 * Unconditional jump to the absolute address specified by the 16-bit register HL.
 */
void INSTR_JUMP_HL(void);

/* RST 0x28 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x28.
 */
void INSTR_RESTART_28(void);

/* RST 0x30 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x30.
 */
void INSTR_RESTART_30(void);

/* RST 0x38 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x38.
 */
void INSTR_RESTART_38(void);

#endif