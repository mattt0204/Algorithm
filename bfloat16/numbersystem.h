#ifndef __NUMBERSYSTEM_H
#define __NUMBERSYSTEM_H
/*
 Support 2 number system
 1) bfloat 16 
*/

typedef union
{ 
 float f; 
 struct
 { 
  unsigned int truncate_mantissa : 16;
  unsigned int mantissa : 7; 
  unsigned int exponent : 8; 
  unsigned int sign : 1; 
 } bfloat16; 
} unpacked_float;



#endif
