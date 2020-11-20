#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// string.format-like function
const char *strf(const char *pfmt,...){

    va_list parg;
    va_start(parg, pfmt);
    size_t sz;

    sz = snprintf(NULL,0,pfmt,parg);
    char *pbuff = (char *) malloc(++sz);

    vsprintf(pbuff,pfmt,parg);
    va_end(parg);

    return pbuff;
}

unsigned int reverse_nbit(unsigned int input, unsigned int shift){

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
