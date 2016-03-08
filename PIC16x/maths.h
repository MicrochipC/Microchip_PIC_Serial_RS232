extern unsigned char maths_temp;

unsigned char rotate_right(unsigned char bitrotate);
unsigned char rotate_left(unsigned char bitrotate);

#define shift_right_thru_carry(number_rotate,carry_rotate)			\
CARRY=carry_rotate;																							\
maths_temp=number_rotate;																				\
asm("RRF _maths_temp,f");																				\
number_rotate=maths_temp

#define shift_left_thru_carry(number_rotate,carry_rotate)				\
maths_temp=number_rotate;																				\
CARRY=carry_rotate;																							\
asm("RLF _maths_temp,f");																				\
number_rotate=maths_temp

