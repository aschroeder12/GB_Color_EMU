#ifndef INCLUDE_GB_REGISTERS_H
#define INCLUDE_GB_REGISTERS_H
/************GAMEBOY REGISTERS **************
 * 
 *  PC (Program Counter) REGISTER 	- 16 BIT
 *  SP (Stack Pointer) REGISTER		- 16 BIT
 *  A (Accumulator) REGISTER 		-  8 BIT
 *  F (Flags) REGISTER 				-  8 BIT
 *  B REGISTER (BC - 16 BIT)		-  8 BIT
 *  C REGISTER (BC - 16 BIT)		-  8 BIT
 *  D REGISTER (DE - 16 BIT)		-  8 BIT
 *  E REGISTER (DE - 16 BIT)		-  8 BIT
 *  H REGISTER (HL - 16 BIT)		-  8 BIT
 *  L REGISTER (HL - 16 BIT)		-  8 BIT
 *  IR (Instruction Register) 		-  8 BIT
 *  IE (Interrupt Enable)			-  8 BIT
 *  IME (Interrupt Master Enable) 	-  8 BIT
 * 
 ********************************************/

/* Constant values used to AND and OR the F_REGISTER to set/reset flags */
const unsigned char ZERO_SET = 0x80;
const unsigned char ZERO_RESET = 0x7f;
const unsigned char SUBTRACTION_SET = 0x40;
const unsigned char SUBTRACTION_RESET = 0xbf;
const unsigned char HALFCARRY_SET = 0x20;
const unsigned char HALFCARRY_RESET = 0xdf;
const unsigned char CARRY_SET = 0x10;
const unsigned char CARRY_RESET = 0xef;

extern unsigned short PC_REGISTER;
extern unsigned short SP_REGISTER;
extern unsigned char BR_MODE;

extern unsigned char A_REGISTER;

/******** FLAGS BITS *************************
 * BIT 		NAME		DESCRIPTION
 * 7		z			Zero Flag
 * 6 		n 			Subtraction Flag (not used?)
 * 5 		h 			Half Carry Flag (not used?)
 * 4		c 			Carry Flag
 *********************************************/
extern unsigned char F_REGISTER;

extern unsigned char B_REGISTER;
extern unsigned char C_REGISTER;
extern unsigned char D_REGISTER;
extern unsigned char E_REGISTER;
extern unsigned char H_REGISTER;
extern unsigned char L_REGISTER;
extern unsigned char IR_REGISTER;
extern unsigned char IME_FLAG;
/******** IE / IF BITS *************************************************************
 * BIT 		NAME		DESCRIPTION	
 * 4		Joypad		Controls whether Joypad Interrupt Handler is being requested
 * 3 		Serial		"" Serial Interrupt Handler
 * 2 		Timer		"" Timer
 * 1		LCD			"" LCD
 * 0 		VBlank		"" VBlank
 ************************************************************************************/
extern unsigned char IE_REGISTER;
extern unsigned char INTERRUPT_FLAG;

/******** LCD CONTROL BITS **********************************************************
 * BIT 		NAME							DESCRIPTION	
 * 7		LCD & PPU enable				Turn Screen/PPU On (1) or Off (0)
 * 6 		Window Tile Map					Window uses 0x9800 (0) or 0x9c00 (1) bg map
 * 5 		Window Enable					Window displayed (1) or not (0)
 * 4		BG & Window Tiles				Addressing Mode for BG and Window, signed (0) unsigned (1)
 * 3 		BG Tile Map						BG Tile Map Area 0x9800+ (0) or 0x9c00+ (1)
 * 2 		OBJ Size						Size of ALL Objects
 * 1		OBJ Enable						Whether Objects are displayed (1) or not (0)
 * 0 		BG & Window enable/priority		Clear both Window and BG and ignore Bit 5 (0) or normal (1)
 ************************************************************************************/
extern unsigned char LCDC_REGISTER;

#endif