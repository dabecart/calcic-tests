#include "simple_floats_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; va_start(ap, c); double sum = 0;
    for(int i=0; i<c; i++) sum += va_arg(ap, double);
    va_end(ap); return (sum == 15.0);
}
