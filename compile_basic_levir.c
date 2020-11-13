#include "cir_macros.h"
#include "cir_builtins.h"

#include "basic.levir"

// language internal:

int main(void) {
    call(main, ());
    return 0;
}
