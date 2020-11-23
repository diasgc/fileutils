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

static inline uint32_t read32_be(void* dst, const char* src) {
	((uint8_t*)dst)[0] = src[0];
	((uint8_t*)dst)[1] = src[1];
	((uint8_t*)dst)[2] = src[2];
	((uint8_t*)dst)[3] = src[3];
    return (uint32_t) 4;
}

static inline uint32_t read32_le(void* dst, const char* src) {
	((uint8_t*)dst)[0] = src[3];
	((uint8_t*)dst)[1] = src[2];
	((uint8_t*)dst)[2] = src[1];
	((uint8_t*)dst)[3] = src[0];
    return (uint32_t) 4;
}

static inline uint32_t read64_be(void * dst, const char * src){
	((uint8_t*)dst)[0] = src[0];
	((uint8_t*)dst)[1] = src[1];
	((uint8_t*)dst)[2] = src[2];
	((uint8_t*)dst)[3] = src[3];
	((uint8_t*)dst)[4] = src[4];
	((uint8_t*)dst)[5] = src[5];
	((uint8_t*)dst)[6] = src[6];
	((uint8_t*)dst)[7] = src[7];
    return (uint32_t) 8;
}

static inline uint32_t read64_le(void * dst, const char * src){
	((uint8_t*)dst)[0] = src[7];
	((uint8_t*)dst)[1] = src[6];
	((uint8_t*)dst)[2] = src[5];
	((uint8_t*)dst)[3] = src[4];
	((uint8_t*)dst)[4] = src[3];
	((uint8_t*)dst)[5] = src[2];
	((uint8_t*)dst)[6] = src[1];
	((uint8_t*)dst)[7] = src[0];
    return (uint32_t) 8;
}

static inline uint32_t read16_be(void* dst, const char* src) {
	((uint8_t*)dst)[0] = src[0];
	((uint8_t*)dst)[1] = src[1];
    return (uint32_t) 2;
}

static inline uint32_t read16_le(void* dst, const char* src) {
	((uint8_t*)dst)[0] = src[1];
	((uint8_t*)dst)[1] = src[0];
    return (uint32_t) 2;
}

static inline uint32_t read8(void * dst, const char * src){
	((uint8_t*)dst)[0] = src[0];
    return (uint32_t) 1;
}

float read_2_14_float(int16_t value){
	return (float(value & 0x3fff) / float(1 << 14)) + (-2 * ((value >> 15) & 0x1) + ((value >> 14) & 0x1));
}
