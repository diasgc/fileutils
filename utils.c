#include <stdio.h>

unsigned int reverse_nbit(unsigned int input, const unsigned int shift){
  unsigned int output = 0;
  unsigned int in = input;
  const unsigned char mask = (1 << shift) - 1;
  while (in != 0)
    {
      output = output << shift;
      output |= (in & mask);
      in = in >> shift;
    }
  // printf ("mask:%o input:%o output:%o", mask, in, output);
  return output;
}
