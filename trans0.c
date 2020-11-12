#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

// bootstrap


#define getsctvar(type, name) name

#define getclsvar(type, name) name; incclsvar(type, name)

#define retsct(type, name) name
#define retcls(type, name) {decname}

// prims
typedef uint32_t prim_uint32;
typedef uint64_t prim_uint64;
typedef int64_t prim_int64;
typedef struct {} prim_empty;



// builtins


typedef struct _sct_bltn_uint32{
    prim_uint32 value;
} type_bltn_uint32;

typedef struct _sct_bltn_uint64{
    prim_uint64 value;
} type_bltn_uint64;

typedef struct _sct_bltn_int64{
    prim_int64 value;
} type_bltn_int64;

//user code
typedef struct _sct_mod_main_Point{
    sct_bltn_uint32 mbr_x;
    sct_bltn_uint32 mbr_y;
} type_mod_main_Point;

// decl fn mod.main.Point.__new__( ...
type_mod_main_Point fn_mod_main_Point___new__(
    type_bltn_uint32 var_arg_x,
    type_bltn_uint32 var_arg_y,
) {
    // args that are calsses are auto inc-ed and added to the locals pool
    // args that are structs do not need incing // incsct(type_bltn_uint32, var_arg_x);
    // args that are structs do not need incing //incsct(type_bltn_uint32, var_arg_y);

    // taking local coppies just to demo format
    type_bltn_uint32 var_lcl_x = getsctvar(var_arg_x, var_arg_x);
    type_bltn_uint32 var_lcl_y = getsctvar(var_arg_y, var_arg_x);
    // newsct and newcls are each a special case
    type_mod_main_Point var_anon_return = newsct(mod_main_Point, {
            getsctvar(type_bltn_uint32, var_lcl_x),
            getsctvar(type_bltn_uint32, var_lcl_y)
    });

    retsct(type_mod_main_Point, var_anon_return)

}


int main(void) {
    // sct_bltn_NothingType var_anon_0 = fn_mod_main_main();
    return 0;
}
