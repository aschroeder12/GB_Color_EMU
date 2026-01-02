#ifndef INCLUDE_GB_INSTR_MATH_8_H
#define INCLUDE_GB_INSTR_MATH_8_H
/* INC R - INCREMENT (REGISTER)
 * Increments data in the 8-bit register R
 */
void INSTR_INC_R(unsigned char*);

/* INC HL - INCREMENT (INDIRECT HL)
 * Increments data at the absolute address specified by the 16-bit register HL.
 */
void INSTR_INC_HL(void);

/* DEC R - DECREMENT (REGISTER)
 * Decrements data in the 8-bit register R
 */
void INSTR_DEC_R(unsigned char*);

/* DEC HL - DECREMENT (INDIRECT HL)
 * Decrements data at the absolute address specified by the 16-bit register HL.
 */
void INSTR_DEC_HL(void);

/* DAA - DECIMAL ADJUST ACCUMULATOR
 * Designed to be used after performing an arithmetic instruction (ADD, ADC, SUB, SBC) 
 * whose inputs were in Binary-Coded Decimal (BCD), adjusting the result to likewise be in BCD.
 */
void INSTR_DAA(void);

/* ADD n - ADD (IMMEDIATE) 0xc6
 * Adds to the 8-bit A register, the immediate data n, and stores the result back into the A register.
 */
void INSTR_ADD_N(void);

/* ADD r - ADD (REGISTER) 0x80 - 0x85, 0x87
 * Adds to the 8-bit A register, the 8-bit register r, and stores the result back into the A register.
 */
void INSTR_ADD_REGISTER_R(unsigned char*);

/* ADD HL - ADD (INDIRECT HL)
 * Adds to the 8-bit A register, data from the absolute address specificed by the 16-bit register HL, 
 * and stores the result back into the A register.
 */
void INSTR_ADD_REGISTER_HL(void);

/* ADC N - ADD WITH CARRY (IMMEDIATE) 
 * Adds to the 8-bit A register, the carry flag and the immediate data n, and stores the result back
 * into the A register.
 */
void INSTR_ADC_N(void);


/* ADC R - ADD WITH CARRY (REGISTER) 0x88 - 0x8d, 0x8f
 * Adds to the 8-bit A register, the carry flag and the 8-bit register r, and stores the result back
 * into the A register.
 */
void INSTR_ADC_REGISTER_R(unsigned char*);

/* ADC HL - ADD with carry (INDIRECT HL)
 * Adds to the 8-bit A register, the carry flag and the data from the absolute address specified
 * by the 16-bit register HL, and stores the result back into the A register.
 */
void INSTR_ADC_REGISTER_HL(void);

/* SUB n - SUBTRACT (IMMEDIATE) 0xd6
 * Subtracts from the 8-bit A register, the immediate data n, and stores the result back into the A
 * register.
 */
void INSTR_SUB_N(void);


/* SUB R - SUBTRACT (REGISTER) 0x90 - 0x95, 0x97
 * Subtracts from the 8-bit A register, the 8-bit register r, and stores the result back into the A
 * register.
 */
void INSTR_SUB_REGISTER_R(unsigned char*);

/* SUB HL - SUB (REGISTER)
 * Subtracts from the 8-bit A register, the 8-bit register HL, and stores the result back into the A
 * register.
 */
void INSTR_SUB_REGISTER_HL(void);

/* SBC N - SUBTRACT WITH CARRY (IMMEDIATE) 
 * Subtracts from the 8-bit A register, the carry flag and the immediate data n, and stores the
 * result back into the A register.
 */
void INSTR_SBC_N(void);

/* SBC R - SUBTRACT WITH CARRY (REGISTER) 0x98 - 0x9d, 0x9f
 * Subtracts from the 8-bit A register, the carry flag and the 8-bit register r, and stores the result
 * back into the A register.
 */
void INSTR_SBC_REGISTER_R(unsigned char *);

/* SBC HL - SUB with carry (INDIRECT HL)
 * Subtracts to the 8-bit A register, the carry flag and the data from the absolute address specified
 * by the 16-bit register HL, and stores the result back into the A register.
 */
void INSTR_SBC_REGISTER_HL(void);

#endif