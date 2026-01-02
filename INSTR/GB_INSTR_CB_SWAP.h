#ifndef INCLUDE_GB_INSTR_CB_SWAP_H
#define INCLUDE_GB_INSTR_CB_SWAP_H
/* SWAP R - SWAP NIBBLES (REGISTER)
 * Swaps the high and low 4-bit nibbles of the 8-bit register R
 */
void INSTR_SWAP_REGISTER_R(unsigned char *);

/* SWAP R - SWAP NIBBLES (INDIRECT HL)
 * Swaps the high and low 4-bit nibbles of the 8-bit data at the absolute address specified by the
 * 16-bit register HL.
 */
void INSTR_SWAP_REGISTER_HL(void);

#endif