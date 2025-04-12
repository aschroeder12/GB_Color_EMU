/* RLA - ROTATE LEFT (ACCUMULATOR)
 * Shift the A_REGISTER bits left by 1, into the Carry Flag.
 * Carry flag goes into bit 0.
 */
void RLA(void);

/* RLCA - ROTATE LEFT CIRCULAR (ACCUMULATOR)
 * Shift the A_REGISTER bits left by 1, bit 7 into the Carry FLAG 
 * AND back around to bit 0, hence the "circular".
 */
void RLCA(void);
