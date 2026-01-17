#include<stdio.h>
#include "raylib.h"
#include "MEMORY_MAP.h"

unsigned char MEM_ScreenPixels[160*144*4] = {255};


/*wooo stack overflow */
int GB_isNthBitSet (unsigned char c, int n) {
    static unsigned char mask[] = {128, 64, 32, 16, 8, 4, 2, 1};
    return ((c & mask[n]) != 0);
}

void PrintScreenMEM()
{
    printf("Print Screen Mem \n");
    for (int i = 0; i < 64; i++)
    {
        printf("%x - ", MEM_ScreenPixels[i]);
    }
    printf("\n");
}


/* Getter for the Screen Memory 
 * Lets us do all our texture updates, and then return the 
 * pointer at the end 
 */
unsigned char* GetScreenMemPtr(void)
{
    return &MEM_ScreenPixels[0];
}

