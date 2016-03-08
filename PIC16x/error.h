#ifndef __ERROR_H
#define __ERROR_H

#define	ERROR_CHECK			TRUE					//detects errors at cost of memory and speed
#define MAX_ERROR				(10 +1)				//if error checking on, how many to handle

//*********************
//normal error checking
//*********************

extern bank1 unsigned int error;							//used to detect errors, only used in debugging

#if	(ERROR_CHECK==TRUE)

extern bank1 unsigned char error_count[];	//used to count errors, only used in debugging

/*

codes in variable unsigned int error, with count in error_count:

Call		error, hex	error, binary				error_count[x]++, <address>=<base>+x
-				0x0					B0000000000000000		<no error>
err(0)	0x1					B0000000000000001		0	 ring buffer overflowed
err(1)	0x2					B0000000000000010		1	 tried to pull data out of ring buffer but nothing there
err(2)	0x4					B0000000000000100		2	 unauthorised interrupt has happened
err(3)	0x8					B0000000000001000		3  flash samples reached max and rolled over
err(4)	0x10				B0000000000010000		4  error in binary search
err(5)	0x20				B0000000000100000		5  uploaded the entire flash
err(6)	0x40				B0000000001000000		6  bad session ID found
err(7)	0x80				B0000000010000000		7  in convert.c, bad index for extra chars found
err(8)	0x100				B0000000100000000		8  in convert.c, getascii_lowlevel(), a valid scancode was not found after a release scancode, 0xF0.  Increase timeout.																						
err(9)	0x200				B0000001000000000		9  in main.c, upload_scancodes_normal(), "Error - could not upload sample no. x"
err(10)	0x400				B0000010000000000		10 in int.c, a get_scancode_error occurred
err(11)	0x800				B0000100000000000		11	
err(12)	0x1000			B0001000000000000		12
err(13)	0x2000			B0010000000000000		13
err(14)	0x4000			B0100000000000000		14
err(15)	0x4000			B1000000000000000		15
*/

#define err(x);	error|=(unsigned int)(1<<(x));error_count[x]++;

#else

#define err(x);	;

#endif	//#if (ERROR_CHECK==TRUE)

#endif	//#ifndef __ERROR_H
