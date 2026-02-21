#include "union_type_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; 
    va_start(ap, c);
    union U u = va_arg(ap, union U);
    va_end(ap); 
    return u.a;
}
