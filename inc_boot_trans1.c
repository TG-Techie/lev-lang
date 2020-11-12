#include "cir_macros.h"
#include "cir_builtins.h"

struct(mod_main_Point, mbrs(
    mbr(x, uint32),
    mbr(y, uint32),
))

class(mod_main_Counter, mbrs(
    mbr(_count, uint32)
))

fn(mod_main_main, (), void, {
     asn(anon_return, new(mod_main_Counter, {litrl_uint32(8)}), uint32)
})

fn(main, (), uint32, {
    dec(foo, mod_main_Counter)
    asn(foo, new(mod_main_Counter, {
        litrl(uint32, 6)
    }), mod_main_Counter)

    dec(foombr, uint32)
    asn(foombr, getmbr(foo, mod_main_Counter, _count, uint32), uint32)
    dbg_print_refcount(foo, mod_main_Counter)
    rel(foo, mod_main_Counter)
    dbg_print_refcount(foo, mod_main_Counter)
    ret(foombr, uint32)
})

int main(void) {
    call(main, ());
    return 0;
}
