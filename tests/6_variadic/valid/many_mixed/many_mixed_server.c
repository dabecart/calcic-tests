#include "many_mixed_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; va_start(ap, c); int sum = 0;
    for(int i=0; i<6; i++) sum += va_arg(ap, int);
    for(int i=0; i<8; i++) sum += (int)va_arg(ap, double);
    sum += va_arg(ap, int);
    va_end(ap); return sum;
}
