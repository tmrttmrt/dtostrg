#ifndef dtostrg_h
#define dtostrg_h

#if defined(ESP8266)
#include "stdlib_noniso.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif
char *dtostrg(double value, signed char width, char prec, char* buff);
#ifdef __cplusplus
} // extern "C"
#endif

#endif