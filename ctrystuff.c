#include <stdint.h>
#include "varad_macro.h"

#define _c_args_from_args(first, ...) ( \
        _first_arg_to_c_##first \
        VARAD_VARNT_MACRO(arg_to_c_, __VA_ARGS__) \
    )
#define VARNT_IMPL_arg_to_c_
#define _first_arg_to_c_arg(name, type) type var_##name
#define VARNT_IMPL_arg_to_c_arg(name, type) , type var_##name

#define _dec_temps_from_args(...)   _dec_temps_from_any(__VA_ARGS__)
#define _dec_temps_from_locals(...) _dec_temps_from_any(__VA_ARGS__)
#define _dec_temps_from_any(...)\
    VARAD_VARNT_MACRO(arg_to_dec_tmp_, __VA_ARGS__)
#define VARNT_IMPL_arg_to_dec_tmp_
#define VARNT_IMPL_arg_to_dec_tmp_arg VARNT_IMPL_arg_to_dec_tmp_any
#define VARNT_IMPL_arg_to_dec_tmp_lcl VARNT_IMPL_arg_to_dec_tmp_any
#define VARNT_IMPL_arg_to_dec_tmp_any(name, type) type tmp_asn_##name;

#define _dec_dflt_from_locals(...)\
    VARAD_VARNT_MACRO(lcl_to_dec_deflt_, __VA_ARGS__)
#define VARNT_IMPL_lcl_to_dec_deflt_
#define VARNT_IMPL_lcl_to_dec_deflt_lcl(name, type) \
    type var_##name = dec_dflt_##type();

#define _rel_from_args(...)   _rel_from_any(__VA_ARGS__)
#define _rel_from_locals(...) _rel_from_any(__VA_ARGS__)
#define _rel_from_any(...)\
    VARAD_VARNT_MACRO(rel_var_, __VA_ARGS__)
#define VARNT_IMPL_rel_var_
#define VARNT_IMPL_rel_var_arg VARNT_IMPL_rel_var_any
#define VARNT_IMPL_rel_var_lcl VARNT_IMPL_rel_var_any
#define VARNT_IMPL_rel_var_any(name, type) rel_##type(var_##name);

#define _paste_frame(...) __VA_ARGS__

#define fn(fnname, rettype, args, locals, frame)\
    rettype fn_##fnname _c_args_from_##args { \
        "comment: the assignment helpers"; \
        _dec_temps_from_##args \
        "comment: dec all local vars"; \
        _dec_dflt_from_##locals \
        "comment: asn helpers for locals"; \
        _dec_temps_from_##locals \
        "comment: enetering function body";\
        _paste_##frame\
        "comment: exiting function body";\
        "comment: return procedure";\
        fn_return_label:\
        _rel_from_##args\
        _rel_from_##locals\
        return _return_tmp_;\
    } \

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
