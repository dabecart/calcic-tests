#include "mixed_int_float_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; va_start(ap, c);
    int i = va_arg(ap, int); double d = va_arg(ap, double); int i2 = va_arg(ap, int);
    va_end(ap); return (i == 1 && d == 2.0 && i2 == 3);
}
