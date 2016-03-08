/*

KeyGhost

Designed by Shane Tolmie Apr 99.

Microprocessor: see mainkg.c

Compiled with:	see mainkg.c

Overall goal: 	lowlevel routines for testing outport ports, disabling interrupts
								and performing a virtual 'processor reset' by defaulting all registers

*/

#include	"pic.h"
#include	"always.h"	//delay routines
#include	"delay.h"		//high level delay routines

//*****************
//TEST OUTPUT PORTS
//*****************

/*

oscillates all ports for output testing

*/
/*
void testports_output(void)
{
	//note: port RA4 MUST HAVE PULLUP resistor

	ADCON1=7;		//set all pins from analogue to digital
	TRISA=0;		//0 = output
	TRISB=0;
	TRISC=0;		

	while(1)
	{
		DelayUs(125);
		PORTA=0xFF;
		PORTB=0xFF;
		PORTC=0xFF;
		DelayUs(125);
		PORTA=0;
		PORTB=0;
		PORTC=0;
	}
}
*/
//**********************
//DISABLE ALL INTERRUPTS
//**********************

void disable_interrupts(void)
{
	while(GIE==1) GIE=0;		//see AM576.  If interrupt occurs just when gie gets set to zero, it won't be cleared
	ADIE=0;
	RCIE=0;
	TXIE=0;
	SSPIE=0;
	CCP1IE=0;
	CCP2IE=0;
	TMR1ON=0;
	TMR1IE=0;
	TMR2ON=0;
	TMR2IE=0;
	INTE=0;
	T0IE=0;
	INTE=0;
	RBIE=0;
	PEIE=0;
}

//***************
//PROCESSOR RESET
//***************

/*

reset all registers to their power on defaults, p136

*/
/*
void processor_reset(void)
{
	while(GIE==1) GIE=0;		//see AM576.  If interrupt occurs just when gie gets set to zero, it won't be cleared
	
	STATUS=0B00011000;
	PORTA=0;
	INTCON=0;
	PIR1=0;
	PIR2=0;
	TMR1L=0;
	TMR1H=0;
	T1CON=0;
	TMR2=0;
	T2CON=0;
	SSPCON=0;
	CCP1CON=0;
	RCSTA=0;
	TXREG=0;
	RCREG=0;
	CCP2CON=0;
	ADCON0=0;
	OPTION=0xFF;
	TRISA=0xFF;
	TRISB=0xFF;
	TRISC=0xFF;
	PIE1=0;
	PIE2=0;
	PCON=0;
	PR2=0xFF;
	SSPADD=0;
	SSPSTAT=0;
	TXSTA=0;
	SPBRG=0;
	ADCON1=0;
}
*/
