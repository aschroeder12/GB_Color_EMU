/* JR e - JUMP RELATIVE
 * Unconditional jump to the relative address specified by the signed 8-bit operand e
 */
void JUMPR(void);

/* JR NZ, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the NON-ZERO condition.
 */
void JUMPR_NZ(void);

/* JR Z, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the ZERO condition.
 */
void JUMPR_Z(void);

/* JR NC, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the NO-CARRY condition.
 */
void JUMPR_NC(void);

/* JR C, e - JUMP RELATIVE (CONDITIONAL)
 * Unconditional jump to the relative address specified by the signed 8-bit operand e,
 * depending on the CARRY condition.
 */
void JUMPR_C(void);

/* RET NZ - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the NON-ZERO condition.
 */
void RETURN_NZ(void);

/* JP NZ - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the NON-ZERO condition.
 */
void JUMP_NZ(void);

/* JP - JUMP
 * Unconditional jump to the absolute address specified by the 16-bit immediate operand.
 */
void JUMP(void);

/* CALL NZ - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the NON-ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_NZ(void);

/* RST 0x00 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x00.
 */
void RESTART_00(void);

/* RET Z - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the ZERO condition.
 */
void RETURN_Z(void);

/* RET - RETURN 
 * Unconditional return from a function
 */
void RETURN(void);

/* JP Z - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void JUMP_Z(void);

/* CALL Z - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the ZERO condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_Z(void);

/* CALL - CALL FUNCTION
 * Unconditional function call to the absolute address specified by the 16-bit operand.
 */
void CALL(void);

/* RST 0x08 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x08.
 */
void RESTART_08(void);

/* RET NC - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the NO-CARRY condition.
 */
void RETURN_NC(void);

/* JP NC - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the NO-CARRY condition.
 */
void JUMP_NC(void);

/* CALL NC - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the NO-CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_NC(void);

/* RST 0x10 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x10.
 */
void RESTART_10(void);

/* RET C - RETURN (CONDITIONAL)
 * Conditional return from a function, depending on the CARRY condition.
 */
void RETURN_C(void);

/* RETI - RETURN FROM INTERRUPT HANDLER
 * Unconditional return from a function. Also enables interrupts by setting IME=1.
 */
void RETURN_IME(void);

/* JP C - JUMP (CONDITIONAL)
 * Conditional jump to the absolute address specified by the 16-bit operand, 
 * depending on the CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void JUMP_C(void);

/* CALL C - CALL (CONDITIONAL)
 * Conditional function call to the absolute address specified by the 16-bit operand, 
 * depending on the CARRY condition.
 * Note that the operand (absolute address) is read even when the condition is false!
 */
void CALL_C(void);

/* RST 0x18 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x18.
 */
void RESTART_18(void);

/* RST 0x20 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x20.
 */
void RESTART_20(void);

/* JP HL - JUMP TO HL
 * Unconditional jump to the absolute address specified by the 16-bit register HL.
 */
void JUMP_HL(void);

/* RST 0x28 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x28.
 */
void RESTART_28(void);

/* RST 0x30 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x30.
 */
void RESTART_30(void);

/* RST 0x38 - RESTART / CALL (IMPLIED)
 * Unconditional function call to the absolute fixed address 0x38.
 */
void RESTART_38(void);

