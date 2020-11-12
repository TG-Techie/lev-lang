#include <stdlib.h>
#include <stdio.h>
#include "varad_macro.h"

// TODO: mkae rel calls for sct and cls call all the proper things
// TODO: add _dec_stmt_def _asn_stmt_def _asnmbr_stmt_def
// TODO: make syntax for setting mbr,  maby separate getmbr() to get( mbrof() )
//  for asn(mbrof(value, name, type) works).

//tools
//  clang -E inc_boot_trans1.c &> foo_out.c; clang-format foo_out.c > foo_out_fmt.c
//  rm a.out; clang inc_boot_trans1.c; ./a.out



//////// MAJOR CHAGNE caller is responcible for reference counting!
//////// the callee is responcible for free-ing.
////////    ie gets, calls, etc, return with rc+1

#define CMT(a) a

typedef uint64_t RefCount;

/* need auto-gen:
new: new_<name>(args ... )
    makes a new instance of the type as a function call
get: get_<name>(self) -> Self
    get a local variable for use in expr
ref: reference: ref_<name>(self) -> void
    for ref-types this takes a refence to it, does nothing for structs.
    any ref must be released at scope exit
rel: release:  rel_<name>(self) -> void
    called when relasing a refernce or local struct. for both cls it decs the
    refcount and frees it if
ret:  ret_<name>(self) -> Self
    does nothing for structs beside pass thorugh, for classes it decs the
    ref count but does not free
getmbr: #this is a macro : getmbr_<name>() -> type(Member)
    used to get members
*/

// declarations



#define fn(fnname, rettype, args, locals, frame)\
    rettype fn_##fnname _c_args_from_##args { \
        _dec_temps_from_##args \
        _dec_dflt_from_##locals \
        _dec_temps_from_##locals \
        _paste_##frame\
        fn_return_label:\
        _rel_from_##args\
        _rel_from_##locals\
        return _return_tmp_;\
    } \



#define class(typename, members)\
    class_body_def(typename, members)\
    class_contentof_internal(typename, members)\
    class_new_expr_def(typename, members)\
    class_get_expr_def(typename, members)\
    class_rel_expr_def(typename, members)\
    class_dec_deflt_def(typename, members)\
    class_ret_def(typename, members)\


#define struct(typename, members)\
    struct_body_def(typename, members)\
    struct_contentof_internal(typename, members)\
    struct_new_expr_def(typename, members)\
    struct_get_expr_def(typename, members)\
    struct_rel_expr_def(typename, members)\
    struct_dec_deflt_def(typename, members)\
    struct_ret_def(typename, members)\

// expressions
#define get(value, type)\
    get_##type(var_##value)

#define call(fnname, args)\
    fn_##fnname args

#define _getmbr_val(value, valtype, mbrname)\
    contentof_##valtype(var_##value).mbr_##mbrname

#define getmbr(value, valtype, mbrname, mbrtype) \
    get_##mbrtype(_getmbr_val(value, valtype, mbrname))

#define new(type, content) \
    new_##type( (content_##type) content)

#define litrl(type, value) \
    litrl_##type(value)


// stamtements

// these are retired since locals/args were introduced to fn syntax
// #define dec(name, type) \
//     type var_##name = dec_dflt_##type();\
//     type tmp_asn_##name;\
//
//
// #define rel(value, type) \
//     rel_##type(var_##value);

#define asn(name, type, value) \
    tmp_asn_##name = var_##name; \
    var_##name = value; \
    rel_##type(tmp_asn_##name);\

#define ret(value, type) type _return_tmp_ = value; goto fn_return_label;
// #define ret(value, type)\
//     return ret_##type(var_##value);

#define brk break;

#define cont continue;

// compound statments
#define loop(body) \
    while (1) body;
/* usage:
    loop({
        code here ...
    })
*/

// debug statments
#define dbg_print_refcount(name, type)\
    printf("`" #name "`'s ref count = %llu\n", var_##name->rc);

///// function macro specifics ///////

#define _c_args_from_args(first, ...) ( \
        _first_arg_to_c_##first \
        VARAD_VARNT_MACRO(arg_to_c_, __VA_ARGS__) \
    )
#define VARNT_IMPL_arg_to_c_
#define _first_arg_to_c_ void // for funcs that take no args
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

///// class and struct specifics /////////

#define contentbody_from_mbrs(...) { VARAD_VARNT_MACRO(contentbody_, __VA_ARGS__) }
#define VARNT_IMPL_contentbody_
#define VARNT_IMPL_contentbody_mbr(name, type) type mbr_##name;

#define cls_relblock_from_mbrs(...) VARAD_VARNT_MACRO(cls_relblock_, __VA_ARGS__)
#define VARNT_IMPL_cls_relblock_
#define VARNT_IMPL_cls_relblock_mbr(name, type) rel_##type(self->content.mbr_##name);


#define class_body_def(typename, members)\
    typedef struct content_##typename\
        contentbody_from_##members\
    content_##typename;\
    typedef struct typename\
        { RefCount rc;\
          content_##typename content;\
        }\
    *typename;

#define class_contentof_internal(typename, members)\
    content_##typename contentof_##typename(typename self){\
        return self->content;\
    }

#define class_new_expr_def(typename, members)\
    typename new_##typename(content_##typename content) {\
        typename self = malloc(sizeof(struct typename));\
        self->rc = 1;\
        self->content = content;\
        return self;\
    }

#define class_get_expr_def(typename, members)\
    typename get_##typename(typename self){\
        self->rc +=1;\
        return self;\
    }

#define class_rel_expr_def(typename, members)\
    void rel_##typename(typename self) {\
        if (self == NULL){return;}\
        self->rc -= 1;\
        if (self->rc == 0){\
            cls_relblock_from_##members\
            free(self);\
        }\
        return;\
    }

#define class_dec_deflt_def(typename, members)\
    typename dec_dflt_##typename(){\
        return NULL;\
    }\

#define class_ret_def(typename, members)\
    typename ret_##typename(typename self){\
        return self;\
    }\


#define copyblock_from_mbrs(...) {VARAD_VARNT_MACRO(copyblock_, __VA_ARGS__)}
#define VARNT_IMPL_copyblock_
#define VARNT_IMPL_copyblock_mbr(name, type) get_##type(self.mbr_##name),

#define sct_relblock_from_mbrs(...) VARAD_VARNT_MACRO(sct_relblock_, __VA_ARGS__)
#define VARNT_IMPL_sct_relblock_
#define VARNT_IMPL_sct_relblock_mbr(name, type) rel_##type(self.mbr_##name);

#define dec_dflt_block_from_mbrs(...) {VARAD_VARNT_MACRO(dec_dflt_, __VA_ARGS__)}
#define VARNT_IMPL_dec_dflt_
#define VARNT_IMPL_dec_dflt_mbr(name, type) dec_dflt_##type(),


#define struct_body_def(typename, members)\
        typedef struct typename\
            contentbody_from_##members\
        typename;\
        typedef typename content_##typename;\

#define struct_contentof_internal(typename, members)\
    content_##typename contentof_##typename(typename self){\
        return self;\
    }

#define struct_new_expr_def(typename, members)\
    typename new_##typename(content_##typename content) {\
        return content;\
    }

#define struct_get_expr_def(typename, members)\
    typename get_##typename(typename self){\
        return (typename) copyblock_from_##members;\
    }

#define struct_rel_expr_def(typename, members)\
    void rel_##typename(typename self){\
        sct_relblock_from_##members\
        return;\
    }

#define struct_dec_deflt_def(typename, members)\
    typename dec_dflt_##typename(){\
        return (typename) dec_dflt_block_from_##members;\
    }\

#define struct_ret_def(typename, members)\
    typename ret_##typename(typename self){\
        return self;\
    }\
