

#define fn(fnname, rettype, args, locals, frame)\
    rettype fn_##fnname ( _c_args_from_##args ) { \
        _dec_dflt_from_##locals \
        _paste_##frame\
        _return_label_:\
        _rel_from_##args\
        _rel_from_##locals\
        return _return_tmp_;\
    } \


// convert back to implicit self
#define method(outertype, methodname, retype, args, locals, frame)\
    retype mthd_##selftype##__##methodname ( _c_args_from_##args ) { \
        _dec_dflt_from_##locals \
        _paste_##frame\
        _return_label_:\
        _rel_from_##args\
        _rel_from_##locals\
        return _return_tmp_;\
    }\


///// function macro specifics ///////

#define _c_args_from_args(first, ...) \
        _first_arg_to_c_##first \
        VARAD_VARNT_MACRO(arg_to_c_, __VA_ARGS__) \

#define VARNT_IMPL_arg_to_c_
#define _first_arg_to_c_ void // for funcs that take no args
#define _first_arg_to_c_arg(name, type) type var_##name
#define VARNT_IMPL_arg_to_c_arg(name, type) , type var_##name

// #define _dec_temps_from_args(...)   _dec_temps_from_any(__VA_ARGS__)
// #define _dec_temps_from_locals(...) _dec_temps_from_any(__VA_ARGS__)
// #define _dec_temps_from_any(...)\
//     VARAD_VARNT_MACRO(arg_to_dec_tmp_, __VA_ARGS__)
// #define VARNT_IMPL_arg_to_dec_tmp_
// #define VARNT_IMPL_arg_to_dec_tmp_arg VARNT_IMPL_arg_to_dec_tmp_any
// #define VARNT_IMPL_arg_to_dec_tmp_lcl VARNT_IMPL_arg_to_dec_tmp_any
// #define VARNT_IMPL_arg_to_dec_tmp_any(name, type) \
//     type tmp_asnvar_##name; \
//     type tmp_mbrof_##name; \

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
