#ifndef INCLUDE_INSTR_CB_BIT_H
#define INCLUDE_INSTR_CB_BIT_H

void INSTR_BIT_REGISTER_R(unsigned char, unsigned char *);
void INSTR_BIT_REGISTER_HL(unsigned char);
void INSTR_RES_REGISTER_R(unsigned char, unsigned char *);
void INSTR_RES_REGISTER_HL(unsigned char);
void INSTR_SET_REGISTER_R(unsigned char, unsigned char *);
void INSTR_SET_REGISTER_HL(unsigned char);

#endif