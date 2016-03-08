/*

Serial port tester

Designed by Shane Tolmie Jun 1999 to May 2001

Microprocessor: 	Microchip PIC18F252

Compiled with:		Hi Tech PICC18 v8.12PL1, MPLAB v5.70.00

Emulated with:		MPLAB ICE 2000 or ICD

Documentation:		all references are to PIC18F252 PDF version of Microchip manual

Overall goal: 		serial port tester @ 19200 baud

Notes: to save memory, you have to comment out a function or else it will be included
even if its never called

*/

//*****
//include header files

#include	<pic18.h>

#include "clk_freq.h" //defines clock speed for micro in MHz, ie: 3.6864Mhz

#include	<conio.h>
#include	<stdlib.h>
#include 	<stdio.h>
#include	<ctype.h>
#include	"always.h"

//****************
//global variables

//*****
//include C files

#include	"delay.h"
#include	"serial.h"
#include	"serial.c"

//#if defined(_16F876) || defined(_16F877) || defined(_16F873) || defined(_16F874) || defined(_16C76)
//	__CONFIG(UNPROTECT|BODEN|FOSC1|BKBUG|WRT);
//#else
//	#error Must be compiled for 16F87x, MPLAB-ICD or 16C76
//#endif

#if defined(_18F252) || defined(_18F452) 
  #warning Compiled for PIC18F252 or PIC18F452
  #if PIC_CLK<8000000
    __CONFIG(1,XT & OSCDIS);
  #else
    __CONFIG(1,HS & OSCDIS);
  #endif
  __CONFIG(2,BORDIS & PWRTEN & WDTDIS);
  __CONFIG(4,LVPDIS);
#else
  #error Unknown microcontroller
#endif

//*************
//main function

void main(void)
{
  unsigned char c;
  unsigned char column;
  
  /*
  //flash lights on port C on dev board
  while(1) {
    PORTC=0x55;
    DelayMs(500);
    PORTC=0xAA;
    DelayMs(500);
  }
  */
	serial_setup();
  
  /*
  while(1) {
    putst("[test @ 19200bps] ");
    DelayMs(200);
  }
  */
  
  //could use printf() here but putst saves 1k of rom space
	putst("\n\n\n");
	putst("Serial tester program for PIC18F252 by Shane Tolmie\n\n");
	putst("From: http://www.workingtex.com/htpic\n\n");
  putst("Starting up serial @ 19200 baud, N,8,1, no flow control ...\n\n");
  
	//go into infinite loop, printing what user types
	column=0;
	for(;;)
	{
		DelayBigMs(333);
		putst("[alive] ");column+=8;
    if (getch_available()==true) {
      c=getch();
      putst("[key pressed: ");column+=14;
      putch(c);column+=1;
      putst("] ");column+=2;
      DelayBigMs(700);
      getch_putch_clear_buffer();
    }
    
    //new line at column 80
    if (column>80) {
      putlf; //new line
      column=0;
    }
	}
}
