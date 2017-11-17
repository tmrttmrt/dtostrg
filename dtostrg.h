#ifndef dtostrg_h
#define dtostrg_h

#define DTOSTR_D

#if defined(ESP8266)
#include "stdlib_noniso.h"
#endif

#define CVTBUFSIZE 16

#ifdef __cplusplus
extern "C"{
#endif
static char *cvt(double arg, int ndigits, int *decpt, int *sign, char *buf, int eflag);
char *dtostrg(double value, signed char width, int prec, char *s);

#ifdef DTOSTR_D
#define D_PRINT(msg,a) debug_print(msg,(double) a) 
void debug_print(char *msg, double d);
#else
#define D_PRINT(msg,a)
#endif

#ifdef __cplusplus
} // extern "C"
#endif


#endif