#include "nested_structs_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; va_start(ap, c);
    struct B b = va_arg(ap, struct B);
    va_end(ap); return (b.a.x == 1 && b.y == 2.0);
}
