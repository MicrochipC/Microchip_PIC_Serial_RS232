/*

KeyGhost

Designed by Shane Tolmie Apr 99.

Microprocessor: see mainkg.c

Compiled with:	see mainkg.c

Overall goal: 	maths routines

*/

#include	<pic.h>
#include	"always.h"
#include	"maths.h"

unsigned char maths_temp;
/*
unsigned char rotate_left(unsigned char bitrotate)
{
	maths_temp=bitrotate;	//change local to global variable
	CARRY=0;

	asm("RLF _maths_temp,f");												//rotate left through carry
	if (maths_temp==0) asm("RLF _maths_temp,f");		//as it goes through carry it must be rotated twice if at end
	return maths_temp;
}
*/
/*
unsigned char rotate_right(unsigned char bitrotate)
{
	maths_temp=bitrotate;	//change local to global variable
	CARRY=0;

	asm("RRF _maths_temp,f");											//rotate right through carry
	if (maths_temp==0) asm("RRF _maths_temp,f");	//as it goes through carry it must be rotated twice if at end
	return maths_temp;
}
*/

		
		
