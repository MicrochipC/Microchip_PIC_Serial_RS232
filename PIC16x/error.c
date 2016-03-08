/*

KeyGhost

Designed by Shane Tolmie Apr 99.

Microprocessor: see mainkg.c

Compiled with:	see mainkg.c

Overall goal: 	keeping track of error occurrences with variables

*/

#include	"always.h"
#include	"error.h"

//variable error is always included so it isn't lost from the watch window when not in use
bank1 unsigned int error;														//used to detect errors, only used in debugging

#if	(ERROR_CHECK==TRUE)

bank1 unsigned char error_count[MAX_ERROR];					//used to count errors, only used in debugging

#endif
