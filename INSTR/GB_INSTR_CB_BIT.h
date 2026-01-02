#ifndef INCLUDE_INSTR_CB_BIT_H
#define INCLUDE_INSTR_CB_BIT_H

/* RLC R - ROTATE LEFT CIRCULAR (REGISTER)
 * Shift the Register R bits left by 1, bit 7 into the Carry FLAG 
 * AND back around to bit 0, hence the "circular".
 */
void INSTR_RLC_REGISTER_R(unsigned char *);

#endif