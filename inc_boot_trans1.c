#include "cir_macros.h"
#include "cir_builtins.h"

struct(mod_main_Point, mbrs(
    mbr(x, uint32),
    mbr(y, uint32),
))

class(mod_main_Counter, mbrs(
    mbr(_count, uint32)
))

// fn(mod_mian_inc_counter, (mod_main_Counter counter), uint32, {
// })

fn(main, uint32,
    args(  ),
    locals( lcl(foo, mod_main_Counter), lcl(foombr, uint32) ),
    frame(
        asn(foo, mod_main_Counter, new(mod_main_Counter, {litrl(uint32, 6)}))

        asn(foombr, uint32, getmbr(foo, mod_main_Counter, _count, uint32))
        dbg_print_refcount(foo, mod_main_Counter)
        ret(get(foombr, uint32), uint32)
    )
)

int main(void) {
    call(main, ());
    return 0;
}
