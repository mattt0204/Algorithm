#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#include "numbersystem.h"
#include "bfloat16_add.h"
#include "bfloat16_mul.h"

void printBinary(unsigned int n, int i) 
{ 
  int k; 
  for (k = i - 1; k >= 0; k--) 
  { 
   if ((n >> k) & 1)   printf("1"); 
   else                printf("0");
  } 
} 

void print_bfloat16(unpacked_float input) 
{ 
 printf("%d | ", input.bfloat16.sign); 
 printBinary(input.bfloat16.exponent, 8); 
 printf(" | ");
 printBinary(input.bfloat16.mantissa, 7); 
 printf(" | ");
 printf(" --> %.10f", input.f);
 printf("\n"); 
} 


#endif