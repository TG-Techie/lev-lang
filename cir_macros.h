#include <stdlib.h>
#include <stdio.h>
#include "varad_macro.h"

#include "cir_mbrof_macro.h"
#include "cir_func_mthd_macro.h"
#include "cir_struct_proxy_macro.h"

// TODO: make proxy into mut, this way mutable struct methods need to use the
//  mut(TypeName) macro. this also menas that while mut_StructType prxoies
//  do need to be gerneated class proxies do not need to exist
// it also means taht it give the language above more grandular controll!


//tools
//  clang -E inc_boot_trans1.c &> foo_out.c; clang-format foo_out.c > foo_out_fmt.c
//  rm a.out; clang inc_boot_trans1.c; ./a.out



//////// MAJOR CHAGNE caller is responcible for reference counting!
//////// the callee is responcible for free-ing.
////////    ie gets, calls, etc, return with rc+1

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

#define class(typename, members)\
    class_body_def(typename, members)\
    class_new_expr_def(typename, members)\
    class_get_expr_def(typename, members)\
    class_rel_expr_def(typename, members)\
    class_dec_deflt_def(typename, members)\
    class_ret_def(typename, members)\
    class_content_ptr_def(typename, members)\


#define struct(typename, members)\
    struct_body_def(typename, members)\
    struct_new_expr_def(typename, members)\
    struct_get_expr_def(typename, members)\
    struct_rel_expr_def(typename, members)\
    struct_dec_deflt_def(typename, members)\
    struct_ret_def(typename, members)\
    struct_content_ptr_def(typename, members)\
    struct_mut_proxy_def(typename, members)

#define mutbl(type) \
    mutble_proxy_##type

#define self(expr, type) \
    expr

#define mutself(expr, type) \
    proxy_##type(&(expr))

// expressions
#define get(subject, type)\
    get_##type(subject)


//fncall(some_fn_name, args())
#define fncall(fnname, args)\
    fn_##fnname (_unpack_##args)

#define mthdcall(selftype, methodname, expr, args)\
    mthd_##selftype##__##methodname ( &(expr), _unpack_##args)

#define _unpack_args(...) __VA_ARGS__

#define new(type, content) \
    new_##type( (content_##type) content)

#define litrl(type, value) \
    litrl_##type(value)


// stamtements

// var asn target
#define var(name, type) \
    var_##name

#define comment(string) \
    string;


#define asn(asntarget, expr, type) \
    {\
        type* target_ptr = &(asntarget); \
        type prev_value = *target_ptr; \
        *target_ptr = expr; \
        rel_##type(prev_value); \
    }\

// turn expression into content ri_cpu_time_qos_user_interactiv
// pass cntn_ptr into fn(cntn_ptr, &(cntn_ptr->mbr_name))

#define ret(expr, type) \
    type _return_tmp_ = expr; goto _return_label_;


#define brk break;

#define cont continue;

// compound statments
#define loop(...) \
    while (1) { __VA_ARGS__ };
/* usage:
    loop({
        code here ...
    })
*/

// debug statments
#define dbg(...) __VA_ARGS__ ;
#define print_refcount(subject, type)\
    printf("`" #subject "`'s ref count = %llu\n", subject->rc);



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

#define class_content_ptr_def(typename, members)\
    content_##typename* content_ptr_##typename(typename* self_ptr){\
        typename self = *self_ptr;\
        return &(self->content);\
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


#define struct_content_ptr_def(typename, members)\
    content_##typename* content_ptr_##typename(typename* self_ptr){\
        return (content_##typename*) self_ptr;\
    }


// this function takes a reference
#define struct_mut_proxy_def(typename, members)\
     _mut_proxy_def(typename)\
     mutble_proxy_##typename proxy_##typename(typename* self){\
         return (mutble_proxy_##typename) self;\
     }\
