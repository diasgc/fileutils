//
// Created by gusta on 15/11/2020.
//

#ifndef DEVXP_R_COMMON_H
#define DEVXP_R_COMMON_H

#endif //DEVXP_R_COMMON_H
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#include <syslog.h>
#ifdef D
#undef D
#endif
#define D(tag,fmt,...)\
    va_list args; \
    syslog(LOG_DEBUG,tag,fmt,args)
#endif
#ifdef __ANDROID__
#include <android/log.h>
#ifdef D
#undef D
#endif
#define D(tag,fmt,...)\
    va_list args; \
    __android_log_vprint(ANDROID_LOG_DEBUG,tag,fmt,args);
#endif


const char* strf(const char* fmt,...);
unsigned int reverse_nbit(unsigned int input, const unsigned int shift);
int indexof(const char *hay, const char *needle, int offset);
bool contains(const char *substring, const char *mainstring);
const char *path_lastsegment(const char *path);
const char *file_extension(const char *path);
const char *path_append(const char *path, const char *segment);
const char *path_parentof(const char *path);
const char *path_resolve(const char *path);