/* LD RR, nn - LOAD 16-BIT REGISTER (IMMEDIATE)
 * Load to the 16-bit register RR, the immediate 16-bit data nn.
 * MSB is R1, LSB is R2!
 */
void INSTR_LOAD_REGISTER_RR_NN(unsigned char *, unsigned char *);

/* LD SP, nn - LOAD 16-BIT REGISTER (IMMEDIATE)
 * Load to the 16-bit SP register, the immediate 16-bit data nn.
 */
void INSTR_LOAD_REGISTER_SP_NN(void)

/* LD nn, SP - LOAD FROM SP (IMMEDIATE)
 * Load to the absolute address specified by the 16-bit operand nn, data from the 16-bit SP register.
 * Yeah it's not technically "Load register", oh well
 */
void INSTR_LOAD_REGISTER_NN_SP(void);

/* POP RR - POP FROM STACK
 * Pops to the 16-bit register rr, data from the stack memory.
 * This instruction does not do calculations that affect flags, but POP AF completely replaces the
 * F register value, so all flags are changed based on the 8-bit data that is read from memory.
 */
void INSTR_POP_RR(unsigned char *, unsigned char *);

/* PUSH RR - PUSH TO STACK
 * Push to the stack memory, data from the 16-bit register RR
 */
void INSTR_PUSH_RR(unsigned char *, unsigned char *);

/* LD SP, HL - LOAD SP FROM HL
 * Load to the 16-bit SP register, data from the 16-bit HL register.
 */
void INSTR_LOAD_REGISTER_SP_HL(void);

/* LD HL, SP+e - LOAD HL FROM ADJUSTED SP
 * Load to the HL register, 16-bit data calculated by adding the signed 8-bit operand e to the 16-
 * bit value of the SP register.
 */
void INSTR_LOAD_REGISTER_HL_ADJSP(void);

