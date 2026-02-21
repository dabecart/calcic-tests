#include "simple_ints_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; va_start(ap, c); int sum = 0;
    for(int i=0; i<c; i++) sum += va_arg(ap, int);
    va_end(ap); return sum;
}
