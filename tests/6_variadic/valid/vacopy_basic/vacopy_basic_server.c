#include "vacopy_basic_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap, ap2; 
    va_start(ap, c); 
    va_copy(ap2, ap);
    int a = va_arg(ap, int); 
    int b = va_arg(ap2, int);
    va_end(ap); 
    va_end(ap2); 
    return (a == b);
}
