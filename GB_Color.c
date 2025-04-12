#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "GB_Registers.h"
#include "/INSTR/GB_INSTR.h"

void Initialization()
{
	PC_REGISTER = 0x0000;
}


int main()
{
	unsigned short opcode;
	PC_REGISTER = 0x0000;

	BootROM();

	/* Load Catridge will eventually have a file path param, but for now hardcode it */
	LoadCartridge();
	while (true)
	{
		opcode = PC_REGISTER;
		PC_REGISTER = PC_REGISTER + 1;
		switch(opcode)
		{
		case 0x0000:
			break;
		}
	}

}

void BootROM(void)
{
	
}
