#include "pass_valist_test.h"
int helper(va_list ap) { return va_arg(ap, int); }
int check(int c, ...) {
    va_list ap; va_start(ap, c);
    int res = helper(ap);
    va_end(ap); return res;
}
