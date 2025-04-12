/* LD BC, A - LOAD FROM ACCUMULATOR (INDIRECT BC)
 * Load to the absolute address specified by the 16-bit register BC, data from the 8-bit A register
 */
void INSTR_LOAD_REGISTER_BC_A(void);

/* LD B, n - LOAD REGISTER (IMMEDIATE)
 * Load to the 8-bit register R, the immediate data n.
 */
void INSTR_LOAD_REGISTER_R_N(unsigned char *);

/* LD A, (BC) - LOAD ACCUMULATOR (INDIRECT BC)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register BC
 */
void INSTR_LOAD_REGISTER_A_BC(void);

/* LD DE, A - LOAD FROM ACCUMULATOR (INDIRECT DE)
 * Load to the absolute address specified by the 16-bit register DE, data from the 8-bit A register
 */
void INSTR_LOAD_REGISTER_DE_A(void);

/* LD A, (DE) - LOAD ACCUMULATOR (INDIRECT DE)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register DE
 */
void INSTR_LOAD_REGISTER_A_DE(void);

/* LD HL+, A - LOAD FROM ACCUMULATOR (INDIRECT HL, INCREMENT)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register.
 * The value of HL is incremented after the memory write
 */
void INSTR_LOAD_REGISTER_HLI_A(void);

/* LD A, (HL+) - LOAD ACCUMULATOR (INDIRECT HL, INCREMENT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL.
 * The value of HL is incremented after the memory read.
 */
void INSTR_LOAD_REGISTER_A_HLI(void);

/* LD HL-, A - LOAD FROM ACCUMULATOR (INDIRECT HL, DECREMENT)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit A register.
 * The value of HL is decremented after the memory write
 */
void INSTR_LOAD_REGISTER_HLD_A(void);

/* LD (HL), n - LOAD REGISTER (IMMEDIATE)
 * Load to the absolute address specified by the 16-bit register HL, the immediate data n
 */
void INSTR_LOAD_REGISTER_HL_N(void);

/* LD A, (HL-) - LOAD ACCUMULATOR (INDIRECT HL, DECREMENT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit register HL.
 * The value of HL is decremented after the memory read.
 */
void INSTR_LOAD_REGISTER_A_HLD(void);

/* LD R, r - LOAD REGISTER (REGISTER)
 * Load to the 8-bit register R, data from the 8-bit register r.
 */
void INSTR_LOAD_REGISTER_R_r(unsigned char *, unsigned char *);
/* LD R, HL - LOAD REGISTER (INDIRECT HL)
 * Load to the 8-bit register R, data from the absolute address
 * specified by the 16-bit register HL
 */
void INSTR_LOAD_REGISTER_R_HL(unsigned char *);

/* LD HL, R - LOAD REGISTER (REGISTER)
 * Load to the absolute address specified by the 16-bit register HL, data from the 8-bit register R.
 */
void INSTR_LOAD_REGISTER_HL_R(unsigned char *);

/* LDH (n), A - LOAD FROM ACCUMULATOR (DIRECT)
 * Load to the address specified by the 8-bit immediate data n, data from the 8-bit A register. The
 * full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the
 * least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_N_A(void);

/* LDH (C), A - LOAD FROM ACCUMULATOR (INDIRECT)
 * Load to the address specified by the 8-bit C register, data from the 8-bit A register. The full
 * 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the least
 * significant byte to the value of C, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_C_A(void);

/* LDH (nn), A - LOAD FROM ACCUMULATOR (DIRECT)
 * Load to the address specified by the 16-bit immediate data nn, data from the 8-bit A register.
 */
void INSTR_LOAD_HW_NN_A(void);

/* LDH A, (n) - LOAD ACCUMULATOR (DIRECT)
 * Load to the 8-bit A register, data from the address specified by the 8-bit immediate data n. The
 * full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the
 * least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_A_N(void);

/* LDH A, (C) - LOAD ACCUMULATOR (DIRECT)
 * Load to the 8-bit A register, data from the address specified by the 8-bit C register. The
 * full 16-bit absolute address is obtained by setting the most significant byte to 0xFF and the
 * least significant byte to the value of n, so the possible range is 0xFF00-0xFFFF.
 */
void INSTR_LOAD_HW_A_C(void);

/* LDH A, (nn) - LOAD ACCUMULATOR (DIRECT)
 * Load to the 8-bit A register, data from the absolute address specified by the 16-bit operand nn.
 */
void INSTR_LOAD_HW_A_NN(void);
