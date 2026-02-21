#include "promotions_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; 
    va_start(ap, c);
    int i = va_arg(ap, int); 
    int j = va_arg(ap, int); 
    double d = va_arg(ap, double);
    va_end(ap); return (i == 1 && j == 2 && d == 3.0);
}
