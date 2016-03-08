#include	<pic.h>

void eeprom_write(unsigned char addr, unsigned char value)
{
	//see 'writing to eeprom memory' in PIC16F876 manual

	bank1 static bit gie_temp;

	EEADR=(unsigned char)(addr);
	EEDATA=(unsigned char)(value);
	EEPGD=0;												//write to EEPROM, not data memory
	gie_temp=GIE;										//save the status of GIE
	WREN=1;													//enable writes
	GIE=0;
	EECON2=0x55;
	EECON2=0xAA;
	WR=1;
	while (!EEIF)
	{
		//do nothing - wait WR to be cleared in hardware
	}
	EEIF=0;													//so it wont trigger false interrupts
	WREN=0;													//disable writes
	GIE=gie_temp;										//restore GIE to previous value
}

#define MY_EEPROM_READ(addr)						\
																				\
( (EEADR=((unsigned char)(addr))),			\
(EEPGD=0),															\
(RD=1),																	\
((unsigned char)EEDATA) )

unsigned char eeprom_read(unsigned char addr)
{
	EEADR=(unsigned char)addr;
	EEPGD=0;
	RD=1;
	return (unsigned char)EEDATA;
}

unsigned int eeprom_read_int(unsigned char addr)
{
	return ((unsigned int)(eeprom_read(addr)) | ((unsigned int)((unsigned int)(eeprom_read((unsigned char)(addr+1)))<<8)));
}

void eeprom_write_int(unsigned char addr, unsigned int data)
{
	eeprom_write(addr,(unsigned char)(data & 0xFF));
	eeprom_write((unsigned char)(addr+1),(unsigned char)(data>>8));
}

