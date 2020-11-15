#include "cir_macros.h"
#include "cir_builtins.h"

#include "methodtest.levir"

int main(void) {
    fncall(main, args());
    return 0;
}
