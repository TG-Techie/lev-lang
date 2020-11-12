#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef int prim_bool;
typedef uint64_t prim_uint64;


int True = 1;
int False = 2;
prim_bool litrl_btln_bool(int lit){
    return (prim_bool) lit;
}

struct Foo {};

typedef struct RefType{
    // need auto-gen: new, get, ref, rel, ret,
    uint64_t rc;
    uint64_t val; // is a non pointer struct so is next to ptr
} *RefType;



RefType new_RefType(uint64_t val){
    RefType self = malloc(struct RefType);
    self->rc = 0;

    self->val = val;
    // etc...
    return self;
}

RefType get_RefType(RefType self){
    self->rc += 1;
    return self;
}


void del_RefType(RefType self){
    self->rc -= 1;
    if (self->rc == 0){
        free(self);
    }
}

RefType ret_RefType(RefType self){
    self->rc -= 1;
    return self;
}

typedef struct ValType{
    uint64_t val;
} ValType;

ValType get_ValType(ValType self){
    return self; // implicitly copied
}


typedef struct RefInValType{
    uint64_t val;
    RefType refed;
} RefInValType;

RefInValType get_RefInValType(RefInValType self){
    get_RefInValType(self.refed);
    return self; // implicitly copied
}


int main(void){
    if (litrl_btln_bool(True)) {
        puts("True");
    } else { if (litrl_btln_bool(False)){
        puts("False");
        }
    }

    // RefType first = malloc(sizeof(struct RefType));
    // first->rc = 1;
    // first->val = 5;
    RefType first = (
        first = malloc(sizeof(struct RefType)),
        first->rc += 1,
        first->content = (RefType_contents) {88,},
        first
    );


    RefType second = (inccnt(first), first);

    printf("first rc %llu\n", first->rc);
    printf("second rc %llu\n", second->rc);

    printf("first..val %llu\n", first->content.val);
    printf("second..val %llu\n", second->content.val);

    first->content.val = 9;

    printf("firs..val %llu\n", first->content.val);
    printf("second..val %llu\n", second->content.val);

    ValType start = {0,}; /*(
        ValType _impl_new_ = {0},
        _impl_new_
    );*/
    ValType other = get_RefInValType(start);
    other.val = 9;

    printf("start %llu\n", start.val);
    printf("other %llu\n", other.val);

    return 0;
}
