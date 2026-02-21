#include "pointers_test.h"
#include <stdarg.h>
int check(int c, ...) {
    va_list ap; va_start(ap, c);
    void *p1 = va_arg(ap, void*); char *p2 = va_arg(ap, char*);
    va_end(ap); return (p1 == p2);
}
