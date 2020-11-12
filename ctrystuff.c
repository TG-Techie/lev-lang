#include <stdint.h>
#include "varad_macro.h"

#define uint32 uint32_t
#define uint64 uint64_t

#define asn(name, val, type) var_##name = val;
#define asn(name, val, type) var_##name = val;
#define ret(value, type) type _return_tmp_ = value; goto fn_return_label;

fn(add_two, uint64,
    args(
        arg(a, uint32),
        arg(b, uint32)
    ),
    locals(
        lcl(c, uint64),
        lcl(fooo, uint64),
    ),
    frame(
        asn(fooo, 5, uint64)
        asn(c, 5, uint64)
        asn(b, 5, uint64)
        ret(get(fooo, uint64), uint64)
    )
)
