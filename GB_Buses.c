/************GAMEBOY BUSES ****************
 * 
 * CARTRIDGE BUS????
 * 16-BIT ADDRESS BUS (Output only)
 * 8-BIT DATA BUS (Bidirectional)
 * SOC INTERRUPT BUS
 * 
 * ALU has 2 8-BIT Input Ports
 * ALU outputs to either the DATA BUS, or 
 * the registers
 * 
 * Independent Increment/Decrement performs
 * simple inc/dec on the 16-bit ADDRESS BUS
 * value. Output always written to registers,
 * either to a 16-bit or pair of 8-bit regs. 
 * 
 * 
 ******************************************/

unsigned short ADDRESS_BUS;
unsigned char DATA_BUS;