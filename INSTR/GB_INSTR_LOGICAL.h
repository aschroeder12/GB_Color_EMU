#ifndef INCLUDE_GB_INSTR_LOGICAL_H
#define INCLUDE_GB_INSTR_LOGICAL_H
/* AND R - AND (REGISTER) 0xa0 - 0xa5, 0xa7
 * Performs a bitwise AND operation between the 8-bit A register and the 8-bit register r, and
 * stores the result back into the A register.
 */
void INSTR_AND_REGISTER_R(unsigned char *);

/* AND N - AND (IMMEDIATE)
 * Performs a bitwise AND operation between the 8-bit A register and immediate data n, and
 * stores the result back into the A register.
 */
void INSTR_AND_N(void);

/* AND HL - AND (INDIRECT HL)
 * Performs a bitwise AND operation between the 8-bit A register and data from the absolute
 * address specified by the 16-bit register HL, and stores the result back into the A register.
 */
void INSTR_AND_REGISTER_HL(void);

/* XOR R - XOR (REGISTER) 0xa8 - 0xad, 0xaf
 * Performs a bitwise XOR operation between the 8-bit A register and the 8-bit register R, and
 * stores the result back into the A register.
 */
void INSTR_XOR_REGISTER_R(unsigned char *);

/* XOR L - XOR (REGISTER)
 * Performs a bitwise XOR operation between the 8-bit A register and data from the absolute 
 * address specified by the 16-bit register HL, and stores the result back into the A register
 */
void INSTR_XOR_REGISTER_HL(void);

/* OR R - OR (REGISTER) 0xb0 - 0xb5, 0xb7
 * Performs a bitwise OR operation between the 8-bit A register and the 8-bit register R, and
 * stores the result back into the A register.
 */
void INSTR_OR_REGISTER_R(unsigned char *);

/* OR N - OR (IMMEDIATE)
 * Performs a bitwise OR operation between the 8-bit A register and immediate data n, and stores
 * the result back into the A register.
 */
void INSTR_OR_N(void);

/* OR HL - OR (INDIRECT HL)
 * Performs a bitwise OR operation between the 8-bit A register and data from the absolute
 * address specified by the 16-bit register HL, and stores the result back into the A register.
 */
void INSTR_OR_REGISTER_HL(void);

/* CP R - CP (REGISTER) 0xb8 - 0xbd, 0xbf
 * Subtracts from the 8-bit A register, the 8-bit register R, and updates flags based on the result.
 * This instruction is basically identical to SUB B, but does not update the A register.
 */
void INSTR_CP_REGISTER_R(unsigned char *);

/* CP HL - CP (INDIRECT HL)
 * Subtracts from the 8-bit A register, data from the absolute address specified by the 16-bit
 * register HL, and updates flags based on the result. This instruction is basically identical to 
 * SUB (HL), but does not update the A register.
 */
void INSTR_CP_REGISTER_HL(void);

/* XOR n - XOR (IMMEDIATE)
 * Performs a bitwise XOR operation between the 8-bit A register and immediate data n, and
 * stores the result back into the A register.
 */
void INSTR_XOR_N(void);

/* CP n - COMPARE (IMMEDIATE)
 * Subtracts from the 8-bit A register, the immediate data n, and updates flags based on the result.
 * This instruction is basically identical to SUB n, but does not update the A register
 */
void INSTR_CP_N(void);

/* CPL - COMPLIMENT ACCUMULATOR
 * Flips all the bits in the 8-bit A register, and sets the N and H flags.
 */
void INSTR_CPL(void);

/* CCF - COMPLIMENT CARRY FLAG
 * Flips the carry flag, and clears the N and H flags
 */
void INSTR_CCF(void);

/* SCF - SET CARRY FLAG
 * Sets the carry flag, and clears the N and H flags
 */
void INSTR_SCF(void);

#endif