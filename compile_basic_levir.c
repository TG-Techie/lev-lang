#include "cir_macros.h"
#include "cir_builtins.h"

#include "basic.levir"

int main(void) {
    call(main, ());
    return 0;
}
