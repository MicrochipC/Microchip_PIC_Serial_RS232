#define	PIC_CLK 4000000 //change this to 3.6864, 4, 16 or 20MHz
//this affects mainser.c, for USART speed, and delay.h for delays

/*

Serial port tester

Designed by Shane Tolmie Jun 1999 to May 2001

Microprocessor: 	Microchip PIC16F87x

Compiled with:		Hitech-C v7.87, MPLAB v5.30.00

Emulated with:		MPLAB ICE 2000 or ICD

Documentation:		all references are to PIC16F87x PDF version of Microchip manual

Overall goal: 		serial port tester @ 19200 baud

Notes: to save memory, you have to comment out a function or else it will be included
even if its never called

*/

//*****
//include header files

#include	<pic.h>
#include	<conio.h>
#include	<stdlib.h>
#include 	<stdio.h>
#include	<ctype.h>
#include	"always.h"
#include	"delay.h"
#include	"error.h"
#include	"maths.h"

//****************
//global variables

//*****
//include C files

#include	"delay.c"
#include	"serial.h"
#include	"serial.c"
//#include	"lowlevel.c"
#include	"error.c"
#include	"maths.c"
#include  "eeprom.c"
#include  "eep_init.c"

#if defined(_16F876) || defined(_16F877) || defined(_16F873) || defined(_16F874) || defined(_16C76)
	__CONFIG(UNPROTECT|BODEN|FOSC1|BKBUG|WRT);
#else
	#error Must be compiled for 16F87x, MPLAB-ICD or 16C76
#endif

//*************
//main function

void main(void)
{
	unsigned char getch_timeout_temp,pass;
  unsigned int i;
  unsigned char c;

	OPTION=0xFF;
	CLRWDT();
	serial_setup();

	//could use printf() here but putst saves 1k of rom space
	putst("\n\n\nPICTest (c)2001 Shane Tolmie - see http://www.workingtex.com/htpic\n");
  putst("Starting up serial @ 19200 baud, N,8,1, no flow control ...\n\n");
  putst("This program tests the serial port.  It displays the text string '[alive]' every\n");
  putst("few seconds, and echoes back to the user the ascii value of the pressed key,\n");
  putst("plus one (+1), ie: putch(getch()+1)\n\n");

	//in this particular .hex file, EEPROM all initialized to 0xEE, check that
	//bootloader has loaded it properly

  putst("If the following test returns [pass] the EEPROM has been all initialized to 0xEE\n");
  putst("by the downloaded .hex file (see eep_init.c). If [fail] it prints out the EEPROM\n");
  putst("contents for your examination.\n\n");
	putst("Testing EEPROM ... ");
  pass=TRUE;
	for (i=0;i<=0xFF;i++) {
		if (eeprom_read((unsigned char)i)!=0xEE)
		{
		  pass=FALSE;
		}
	}
	if (pass==TRUE) {
	  putst("[pass]");
	}
	else {
	  putst("[FAIL]\n");

  	//dump contents of EEPROM to screen
		for (i=0;i<=0xFF;i++)
		{
			putchhex(i);
			putst("=");
			putchhex(eeprom_read((unsigned char)i));
			putst(" - ");
		}
		putlf;
	}
	putlf;
	putlf;

	//go into infinite loop, printing what user types
	putst("Key pressed:\n\n");
  c=0;
	for(;;)
	{
		getch_timeout_temp=getch_timeout();

		if (getch_timeout_temp==0) {
			putst("[alive] ");	//could use printf here but its too big!
      c++;
      if (c>8) {
        c=0;
        putlf;
      }
		}
		else {
			putch(getch_timeout_temp+1);
			putlf;
		}
	}
}
