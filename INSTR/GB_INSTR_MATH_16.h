/* INC rr - INCREMENT (16-BIT REGISTER, except SP)
 * Increments data in the 16-bit register rr. MSB is R1, LSB is R2!
 */
void INC_RR(unsigned char *, unsigned char *);

/* INC SP - INCREMENT (SP REGISTER)
 * Increments data in the SP Register
 */
void INC_SP(void);

/* DEC rr - DECREMENT (16-BIT REGISTER, except SP)
 * Decrements data in the 16-bit register rr. MSB is R1, LSB is R2!
 */
void DEC_RR(unsigned char *, unsigned char *);

/* DEC SP - DECREMENT (SP REGISTER)
 * Decrements data in the SP Register
 */
void DEC_SP(void);

/* ADD HL, rr - ADD (16-BIT REGISTER, except SP)
 * Adds to the 16-bit HL register pair, the 16-bit register rr, and 
 * stores the result back into the HL register pair.
 * R1 is MSB, R2 is LSB
 * I might be able to get away with doing it the way I am.
 * If there are issues, you need to add L and C first, then
 * calculate the carry bit, then also add that to H + B. 
 */
void ADD_HL_RR(unsigned char *, unsigned char *);

/* ADD HL, SP - ADD (SP)
 * Adds to the 16-bit HL register pair, the SP REGISTER, and stores the result back into the HL
 * register pair.
 */
void ADD_HL_SP(void);

/* ADD SP, e - ADD TO STACK POINTER (RELATIVE)
 * Loads to the 16-bit SP register, 16-bit data calculated by adding the signed 8-bit operand e to
 * the 16-bit value of the SP register.
 */
void ADD_SP_E(void);

