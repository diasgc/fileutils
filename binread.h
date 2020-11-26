#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define FMT_DEC         0
#define FMT_HEX         1
#define FMT_OCT         2
#define FMT_BIN         3

#define BIG_ENDIAN      0;
#define LITTLE_ENDIAN   1;

static inline uint32_t read32_be(void* dst, const char* data) {
    ((uint8_t*)dst)[0] = data[0];
    ((uint8_t*)dst)[1] = data[1];
    ((uint8_t*)dst)[2] = data[2];
    ((uint8_t*)dst)[3] = data[3];
    return (uint32_t) 4;
}

static inline uint32_t read32_le(void* dst, const char* data) {
    ((uint8_t*)dst)[0] = data[3];
    ((uint8_t*)dst)[1] = data[2];
    ((uint8_t*)dst)[2] = data[1];
    ((uint8_t*)dst)[3] = data[0];
    return (uint32_t) 4;
}

static inline uint32_t read64_be(void * dst, const char * data){
    ((uint8_t*)dst)[0] = data[0];
    ((uint8_t*)dst)[1] = data[1];
    ((uint8_t*)dst)[2] = data[2];
    ((uint8_t*)dst)[3] = data[3];
    ((uint8_t*)dst)[4] = data[4];
    ((uint8_t*)dst)[5] = data[5];
    ((uint8_t*)dst)[6] = data[6];
    ((uint8_t*)dst)[7] = data[7];
    return (uint32_t) 8;
}

static inline uint32_t read64_le(void * dst, const char * data){
    ((uint8_t*)dst)[0] = data[7];
    ((uint8_t*)dst)[1] = data[6];
    ((uint8_t*)dst)[2] = data[5];
    ((uint8_t*)dst)[3] = data[4];
    ((uint8_t*)dst)[4] = data[3];
    ((uint8_t*)dst)[5] = data[2];
    ((uint8_t*)dst)[6] = data[1];
    ((uint8_t*)dst)[7] = data[0];
    return (uint32_t) 8;
}

static inline uint32_t read16_be(void* dst, const char* data) {
    ((uint8_t*)dst)[0] = data[0];
    ((uint8_t*)dst)[1] = data[1];
    return (uint32_t) 2;
}

static inline uint32_t read16_le(void* dst, const char* data) {
    
    ((uint8_t*)dst)[0] = data[1];
    ((uint8_t*)dst)[1] = data[0];
    return (uint32_t) 2;
}

// uint8:       8-bit unsigned integer.
typedef struct {

    uint8_t value;

    uint32_t read(const char *data){
        value = data[0];
        return 1;
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%02x", value);
            case 2: return strf("0%o", value);;
        }
        return strf("%d", value);
    }

} uint8;

// int8:        8-bit signed integer.
typedef struct {

    int8_t value;

    uint32_t read(const char *data){
        value = data[0];
        return 1;
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%02x", value);
            case 2: return strf("0%o", value);;
        }
        return strf("%d", value);
    }

 } int8;

// uint16:      16-bit unsigned integer.
typedef struct {

    uint16_t value;

    uint32_t read(int le, const char *data){
        if (le) read16_le(&value, data); else read16_be(&value, data);
        return 2;
    }
    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%04x", value);
            case 2: return strf("0%02o", value);;
        }
        return strf("%d", value);
    }
} uint16;

// int16:       16-bit signed integer.
typedef struct {

    int16_t value;

    uint32_t read(int le, const char *data){
        if (le) read16_le(&value, data); else read16_be(&value, data);
        return 2;
    }
    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%04x", value);
            case 2: return strf("0%02o", value);;
        }
        return strf("%d", value);
    }
} int16;	    

// uint24:      24-bit unsigned integer.
#pragma pack(push, 1)
typedef struct {

    uint8_t value[3];

    uint32_t read(uint8_t le, const char *data){
        if (le) {
            value[0] = data[2];
            value[1] = data[1];
            value[2] = data[0];
        } else {
            value[0] = data[0];
            value[1] = data[1];
            value[2] = data[2];
        }
        return (uint32_t) 3;
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%04x", Value());
            case 2: return strf("0%02o", Value());;
        }
        return strf("%d", value);
    }

    uint32_t Value(){
        return (uint32_t) ((uint32_t) value[0] | ((uint32_t) value[1] << 8) | ((uint32_t) value[2] << 16));
    }

} uint24;    // 24-bit unsigned integer.
#pragma pack(pop)

// uint32:      32-bit unsigned integer.
typedef struct {

    uint32_t value;

    uint32_t read(int le, const char *data){
        return le ? read32_le(&value, data) : read32_be(&value, data);
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%06x", value);
            case 2: return strf("0%03o", value);;
        }
        return strf("%d", value);
    }
} uint32;

// int32:       32-bit signed integer.
typedef struct {

    int32_t value;

    uint32_t read(int le, const char *data){
        return le ? read32_le(&value, data) : read32_be(&value, data);
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%06x", value);
            case 2: return strf("0%03o", value);;
        }
        return strf("%d", value);
    }
} int32;	    

// uint64:      64-bit unsigned long.
typedef struct {

    uint64_t value;

    uint32_t read(int le, const char *data){
        return le ? read64_le(&value, data) : read64_be(&value, data);
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%0x", value);
            case 2: return strf("0%0o", value);;
        }
        return strf("%d", value);
    }
} uint64;

// int64:       64-bit signed long.
typedef struct {

    int64_t value;

    uint32_t read(int le, const char *data){
        return le ? read64_le(&value, data) : read64_be(&value, data);
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%0x", value);
            case 2: return strf("0%0o", value);;
        }
        return strf("%d", value);
    }
} int64;

// Tag:         Array of four uint8s (length = 32 bits) used to identify a table, design-variation axis, script, language system, feature, or baseline
typedef struct { 
    
    char b[4];
    
    uint32_t read(int le, const char* data){
        ((char*)b)[0] = data[0];
        ((char*)b)[1] = data[1];
        ((char*)b)[2] = data[2];
        ((char*)b)[3] = data[3];
        return 4;
    }

    const char* c_str(){
        return strf("%.4s",b);
    }

} Tag;

// Offset16:    Short offset to a table, same as uint16, NULL offset = 0x0000
typedef uint16  Offset16;

// Offset32:    Long offset to a table, same as uint32, NULL offset = 0x00000000
typedef uint32  Offset32;

// Fixed:       32-bit signed fixed-point number (16.16)
typedef struct {

    uint32_t value;

    uint32_t read(int le, const char *data){
        return le ? read32_le(&value, data) : read32_be(&value, data);
    }

    const char* c_str(int fmt){
        switch(fmt){
            case 1: return strf("0x%0x", value);
            case 2: return strf("0%0o", value);;
        }
        return strf("%d", value);
    }

    float Value(){
        return value / 65536.0;
    }

} Fixed;

// FWORD:       int16 that describes a quantity in font design units.
typedef int16   FWORD;

// UFWORD:      uint16 that describes a quantity in font design units.
typedef uint16  UFWORD;

// F2DOT14:     16-bit signed fixed number with the low 14 bits of fraction (2.14).
typedef struct {
    
    uint16_t b;

    uint32_t read(int le, const char* data){
        return le ? read16_le(&b,data) : read16_be(&b,data);
    }

    float value(){
        //(float(value & 0x3fff) / float(1 << 14)) + (-2 * ((value >> 15) & 0x1) + ((value >> 14) & 0x1));
        uint16_t v = b;
        float s = (float) ((0xC000 & v) >> 14);
        v &= 0x3FFF;
        s += ((float) v) / 16383.f; //16383 == 0x3FFF
        return s;
    }

    const char* c_str(){
        return strf("%f%",value());
    }

} F2DOT14;

// Version16Dot16: Packed 32-bit value with major and minor version numbers. (See Table Version Numbers.)
typedef struct {

    uint16_t major;
    uint16_t minor;

    uint32_t read(int le, const char* data){
        return le ?
            read16_le(&major,data) + read16_le(&minor,data + 2) :
            read16_be(&major,data) + read16_be(&minor,data + 2);
    }

    const char* c_str(){
        return strf("%d.%d", major, minor);
    }

} Version16Dot16;

// LONGDATETIME Date and time represented in number of seconds since 12:00 midnight, January 1, 1904, UTC. The value is represented as a signed 64-bit integer.
typedef struct {

    int64_t value;

    uint32_t read(int le, const char* data){
        return le ? read64_le(&value, data) : read64_be(&value, data);
    }

    const char* c_str(){
        return strf("%d", value);
    }

} LONGDATETIME;	
