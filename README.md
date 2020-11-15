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

fn(main, uint16, args(), 
    locals( lcl(x, uint16) ), // list all local variables
    frame( 
        // x = 16;
        asn( // =
            var(x, uint16), // x
            litrl(uint16, 0), // 16
            uint16
        )
        // return x;
        ret(get(var(x, uint16), uint16))
    )
)
```

c preprocessor macors would then expand this into c version and auto generate helper fiunctions for handling the classes and structs
