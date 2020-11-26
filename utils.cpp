//
// Created by gusta on 15/11/2020.
//

#include <unistd.h>
#include <string.h>
#include "utils.h"
#if (WIN32)
#define PATH_SEP '\'
#else
#define PATH_SEP '/'
#endif

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

const char *path_resolve(const char *path){
    char lnk[256];
    int rl = readlink(path, lnk, sizeof(lnk)-1);
    if (rl > -1) {
        lnk[rl] = '\0';
        return (const char *) &lnk;
    }
    return path;
}

const char *path_lastsegment(const char *path){

    const char *result = strrchr(path,PATH_SEP);
    return result == NULL ? path : ++result;
}


const char *file_extension(const char *path){
    const char *result = strrchr(path,'.');
    return result == NULL || result == path ? NULL : ++result;
}

const char *path_append(const char *path, const char *new_segment){
    size_t sz = strlen(path) + strlen(new_segment) + 2;
    char *newpath = (char *) malloc(sz);
    snprintf(newpath,sz,"%s/%s",path,new_segment);
    return newpath;
}

const char *path_parentof(const char *path){
    const char *ppos = strrchr(path,PATH_SEP);
    size_t sz = ppos - path;
    char *dst = (char *)malloc(sz + 1);
    strncpy(dst, path, sz);
    return dst;
}