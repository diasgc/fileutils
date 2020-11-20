#include <stdio.h>

unsigned int reverse_nbit(unsigned int input, const unsigned int shift){
  
  // no shift no action
  if (shift == 0)
    return input;

  unsigned int output = 0;
  unsigned int in = input;
  
  // set max shift to 7 bits
  shift = shift & 0xf;
  const unsigned char mask = (1 << shift) - 1;
  
  while (in != 0){
    output = output << shift;
    output |= (in & mask);
    in = in >> shift;
  }

  // printf ("mask:%o input:%o output:%o", mask, in, output);
  return output;
}
