#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/** Enforce timing function
 * The "wait" function used to keep the timing of each action aligned with where it should be.
 * The wait param needs to be calculated before being passed in
 * @param {clock_t} wait The ending time we want to wait until. 
 */
void enforce_timing(clock_t wait)
{
	while (wait > clock())
	{
		// spin baby spin
	}
}



int main()
{
	clock_t begin, end;
	int waitCycles;

	begin = clock();
	waitCycles = CLOCKS_PER_SEC * (double)(1);

	// do stuff

	enforce_timing(begin + waitCycles);
	end = clock();
	printf("%d\n", CLOCKS_PER_SEC);
	printf("%d\n", begin );
	printf("%d\n", end);


}
