/*

KeyGhost

Designed by Shane Tolmie Apr 99.

Microprocessor: see mainkg.c

Compiled with:	see mainkg.c

Overall goal: 	Delay Routines

*/

#ifndef __DELAY_C
#define __DELAY_C

#include	"always.h"
#include	"delay.h"

void DelayBigUs(unsigned int cnt)
{
	unsigned char	i;

	i = (unsigned char)(cnt>>8);
	while(i>=1) 
	{
		i--;		
		DelayUs(253);
		CLRWDT();
	} 
	DelayUs((unsigned char)(cnt & 0xFF));
}


void DelayMs(unsigned char cnt)
{
	unsigned char	i;
	do {
		i = 4;
		do {
			DelayUs(250);
			CLRWDT();
		} while(--i);
	} while(--cnt);
}
/*
//this copy is for the interrupt function
void DelayMs_interrupt(unsigned char cnt)
{
	unsigned char	i;
	do {
		i = 4;
		do {
			DelayUs(250);
		} while(--i);
	} while(--cnt);
}
*/

void DelayBigMs(unsigned int cnt)
{
	unsigned char	i;
	do {
		i = 4;
		do {
			DelayUs(250);
			CLRWDT();
		} while(--i);
	} while(--cnt);
}

/*
void DelayS(unsigned char cnt)
{
	unsigned char i;
	do {
		i = 4;
		do {
			DelayMs(250);
			CLRWDT();
		} while(--i);
	} while(--cnt);
}
*/

#endif

