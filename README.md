# lev-lang

This is a dsl used as a proof of concept that a hihger level object / struct based language could be translated to c using macros.

this project has been retired as while proven macros do not allow recursive macro evaluation. That means teh expression cannot be recursively written


### Code Examples:
defining a structs and classes: 
```c
// structs have value semantics
struct(mod_main_Point, mbrs(
    mbr(x, uint32), // defines a member on the type
    mbr(y, uint32),
))

// whereas classes have refence semantics
class(mod_main_Counter, mbrs(
    mbr(_count, uint32)
))

// example of a function def
/*
int32_t main(void){
    int32_t x;
    x = 0;
    return x;
}
*/
fn(main, uint32, args(), 
    locals( lcl(x, uint32) ), // list all local variables
    frame( 
        asn(var(x, uint32), 
            litrl(uint32, 0),
            uint32
        )
        ret(get(var(x, uint32), uint32))
    )
)
```

c preprocessor macors would then expand this into c version and auto generate helper fiunctions for handling the classes and structs
