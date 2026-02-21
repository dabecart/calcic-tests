#include "struct_medium_test.h"
#include <stdarg.h>
int check(int count, ...) {
    va_list ap; va_start(ap, count);
    struct S s = va_arg(ap, struct S);
    va_end(ap); return (s.a + s.d);
}
