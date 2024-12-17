#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"GB_Registers.h"

/** Enforce timing function
 * The "wait" function used to keep the timing of each action aligned with where it should be.
 * The wait param needs to be calculated before being passed in
 * @param {clock_t} wait The ending time we want to wait until. 
 */
void EnforceTiming(clock_t wait)
{
	while (wait > clock())
	{
		// spin baby spin
	}
}

void Initialization()
{
	PC_REGISTER = 0x00;
}


int main()
{
	clock_t begin, end;
	int waitCycles;
	unsigned short opcode;



	begin = clock();
	waitCycles = CLOCKS_PER_SEC * (double)(1);

	// do stuff
	opcode = ReadMemory(ADDRESS_BUS = PC_REGISTER);
	PC_REGISTER = PC_REGISTER + 1;

	switch(opcode)
	{
	case 0x40: // LOAD_REGISTER_B_B
		LOAD_REGISTER_B_B();
		break;
	default:
		// aaaaaaaaaaaa
	}







	EnforceTiming(begin + waitCycles);
	end = clock();
	printf("%d\n", CLOCKS_PER_SEC);
	printf("%d\n", begin );
	printf("%d\n", end);


}
