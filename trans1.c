#include "cir_macros.h"

struct(uint32, {
    mbr(value, uint32_t)
})

uint32 litrl_uint32(uint32_t val){
    return (uint32){val}; // structs do not need new
}


uint32 get_uint32(uint32 self){
    return self; // get copies
}

void ref_uint32(uint32 self){
    return; // reference takes no actions for empty structs
}

void rel_uint32(uint32 self){
    return; // no action on release
}

uint32 ret_uint32(uint32 self){
    return self; // no action on release
}

// struct full template
struct(mod_main_Point, {
    mbr(x, uint32)
    mbr(y, uint32)
})
// typedef struct mod_main_Point {
//     uint32 mbr_x;
//     uint32 mbr_y;
// } mod_main_Point;

mod_main_Point new_mod_main_Point(
    uint32 lcl_x,
    uint32 lcl_y
    //some_ref_type some_ref_argument
){
    ref_uint32(lcl_x);
    ref_uint32(lcl_y);
    //ref_some_ref_type(some_ref_argument);
    return (mod_main_Point){
        lcl_x,
        lcl_y,
        // some_ref_argument,
    };
}



mod_main_Point get_mod_main_Point(mod_main_Point self){
    // for structs get returns a copy of the data and manages cls ref counts
    mod_main_Point copy = (mod_main_Point){
        get_uint32(self.mbr_x), // accounts for inner structs w/ refs
        get_uint32(self.mbr_y)
    };
    // for ref item in self
    //ref_some_ref_cls(copy.mbr_ref)
    return copy;
}

void ref_mod_main_Point(mod_main_Point self){
    // for member in self, ref
    ref_uint32(self.mbr_x);
    ref_uint32(self.mbr_y);
    // for ref classes this covers the rc
    //ref_some_cls_mbr(self.mbr_ref)
    return;
}

void rel_mod_main_Point(mod_main_Point self){
    rel_uint32(self.mbr_x);
    rel_uint32(self.mbr_y);
    return;
}

// class full template
class(mod_main_Counter, {
        mbr(_count, uint32)
    })
// typedef struct mod_main_Counter {
//     RefCount rc;
//     struct content_mod_main_Counter {
//         uint32 mbr__count;
//     } content;
// } *mod_main_Counter;



mod_main_Counter new_mod_main_Counter(uint32 _count){
    ref_uint32(_count);

    mod_main_Counter self = malloc(sizeof(struct mod_main_Counter));
    self->rc = 0;

    self->content = (struct content_mod_main_Counter){
        _count
    };

    return self;
}

mod_main_Counter get_mod_main_Counter(mod_main_Counter self){
    return self;
}

void ref_mod_main_Counter(mod_main_Counter self){
    self->rc += 1;
    return;
}

void rel_mod_main_Counter(mod_main_Counter self){
    if (self == NULL){
        return;
    }

    self->rc -= 1;
    if (self->rc == 0){
        free(self);
    }
    return;
}

mod_main_Counter ret_mod_main_Counter(mod_main_Counter self){
    self->rc -= 1;
    return self;
}


// function full template
fn(mod_main_Counter_count, (mod_main_Counter self), uint32, {
    ref(self, mod_main_Counter)
    dec(anon_return, uint32)
    // asn(anon_return, get(self->content.mbr__count, uint32), uint32)
    asn(anon_return, getmbr(self, _count, mod_main_Counter), uint32)

    rel(self, mod_main_Counter) // anon_return is not released b/c
    ret(get(anon_return, uint32), uint32)
})
// uint32 fn_mod_main_Counter_count(mod_main_Counter self){
//     ref(self, mod_main_Counter)
//     dec(anon_return, uint32)
//     asn(anon_return, get(self->content.mbr__count, uint32), uint32)
//
//     rel(self, mod_main_Counter) // anon_return is not released b/c
//     ret(get(anon_return, uint32), uint32)
// }

int main(void){
    // al the variabels in the scope must be pre-defined
    //  and classes must be nulled (to simplify asn syntax)
    mod_main_Point lcl_point;
    mod_main_Counter lcl_cntr = NULL;
    uint32 lcl_cnt;
    uint32 lcl_x;
    uint32 lcl_y; // for test of asn() syntax

    rel_mod_main_Point(lcl_point);
    lcl_point = new_mod_main_Point(
        litrl_uint32(127),
        litrl_uint32(255)
    ); ref_mod_main_Point(lcl_point);

    rel_mod_main_Counter(lcl_cntr);
    lcl_cntr = new_mod_main_Counter(
        litrl_uint32(76)
    ); ref_mod_main_Counter(lcl_cntr);

    // expanded syntax for  getting a member from a class instance
    rel_uint32(lcl_cnt);
    lcl_cnt = get_uint32(lcl_cntr->content.mbr__count); // kown get
    ref_uint32(lcl_cnt);

    // extended syntax for getting a member from a class instance
    rel_uint32(lcl_x);
    lcl_x = get_uint32(lcl_point.mbr_x);
    ref_uint32(lcl_x);

    // rel_uint32(lcl_y);
    // lcl_y = get_uint32(lcl_point.mbr_y);
    // ref_uint32(lcl_y);

    asn(lcl_y, get(lcl_point.mbr_y, uint32), uint32);

    printf("%u\n", lcl_cnt);
    printf("%u\n", lcl_x);
    printf("%u\n", lcl_y);


    return 0;
}
