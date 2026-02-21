#include "struct_small_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; va_start(ap, c);
    struct S s = va_arg(ap, struct S);
    va_end(ap); return (s.a == 5 && s.b == 10);
}
