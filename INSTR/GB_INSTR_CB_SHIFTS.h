/* RLC R - ROTATE LEFT CIRCULAR (REGISTER)
 * Shift the Register R bits left by 1, bit 7 into the Carry FLAG 
 * AND back around to bit 0, hence the "circular".
 */
void INSTR_RLC_REGISTER_R(unsigned char *);

/* RLC (HL) - ROTATE LEFT CIRCULAR (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL left 1 bit, bit 7 into the Carry FLAG 
 * AND back around to bit 0, hence the "circular".
 */
void INSTR_RLC_REGISTER_HL(void);

/* RRC R - ROTATE RIGHT CIRCULAR (REGISTER)
 * Shift the Register R bits right by 1, bit 0 into the Carry FLAG 
 * AND back around to bit 7, hence the "circular".
 */
void INSTR_RRC_REGISTER_R(unsigned char *);

/* RRC (HL) - ROTATE RIGHT CIRCULAR (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL right 1 bit, bit 0 into the Carry FLAG 
 * AND back around to bit 7, hence the "circular".
 */
void INSTR_RRC_REGISTER_HL(void);

/* RL - ROTATE LEFT (REGISTER)
 * Shift the Register R bits left by 1, into the Carry Flag.
 * Carry flag goes into bit 0.
 */
void INSTR_RL_REGISTER_R(unsigned char *);

/* RL - ROTATE LEFT (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL left by 1, into the Carry Flag.
 * Carry flag goes into bit 0.
 */
void INSTR_RL_REGISTER_HL(void);

/* RR - ROTATE RIGHT (REGISTER)
 * Shift the Register R bits right by 1, into the Carry Flag.
 * Carry flag goes into bit 7.
 */
void INSTR_RR_REGISTER_R(unsigned char *);

/* RR - ROTATE RIGHT (INDIRECT HL)
 * Shift the 8 bit data at the address specified by the 16-bit register HL bits right by 1, into the Carry Flag.
 * Carry flag goes into bit 7.
 */
void INSTR_RR_REGISTER_HL(void);

/* SLA - SHIFT LEFT ARITHMETIC (REGISTER)
 * Shift the Register R value left by one bit using an arithmetic shift
 * Bit 7 goes into Carry Flag, bit 0 is set to 0. 
 */
void INSTR_SLA_REGISTER_R(unsigned char *);

/* SLA - SHIFT LEFT ARITHMETIC (INDIRECT HL)
 * Shift the 8-bit value at the address specified by the HL register left by one bit using an arithmetic shift
 * Bit 7 goes into Carry Flag, bit 0 is set to 0. 
 */
void INSTR_SLA_REGISTER_HL(void);

/* SRA - SHIFT RIGHT ARITHMETIC (REGISTER)
 * Shift the Register R value right by 1, into the Carry Flag.
 * Bit 7 retains its value, bit 0 to Carry Flag.
 */
void INSTR_SRA_REGISTER_R(unsigned char *);

/* SRA - SHIFT RIGHT ARITHMETIC (INDIRECT HL)
 * Shift the 8-bit value at the address specified by the HL register right by 1, into the Carry Flag.
 * Bit 7 retains its value, bit 0 to Carry Flag.
 */
void INSTR_SRA_REGISTER_HL(void);
