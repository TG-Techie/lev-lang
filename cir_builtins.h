#include <stdint.h>
//#include <stdio.h>
#include <stdbool.h>
//#include <stdarg.h>
#include "cir_macros.h"

#define _builtin_struct(typename, nativename, dec_default_value)\
    typedef struct typename { nativename native; } typename;\
    typedef typename content_##typename;\
    content_##typename contentof_##typename(typename self) { return self; }\
    typename litrl_##typename(nativename val){ return (typename){val}; }\
    typename get_##typename(typename self){ return self; }\
    void rel_##typename(typename self){ return; }\
    typename dec_dflt_##typename() { return (typename) {dec_default_value}; }\
    typename ret_##typename(typename self) { return self; }\

_builtin_struct(int8,    int8_t,    0)
_builtin_struct(int16,   int16_t,   0)
_builtin_struct(int32,   int32_t,   0)
_builtin_struct(int64,   int64_t,   0)

_builtin_struct(uint8,   uint8_t,   0)
_builtin_struct(uint16,  uint16_t,  0)
_builtin_struct(uint32,  uint32_t,  0)
_builtin_struct(uint64,  uint64_t,  0)

_builtin_struct(float32, float,     0)
_builtin_struct(float64, double,    0)
