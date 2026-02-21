#include "vacopy_loop_test.h"
#include <stdarg.h>

int check(int c, ...) {
    va_list ap; 
    va_start(ap, c); 
    int sum = 0;
    
    for(int i=0; i<c; i++) {
        va_list tmp; 
        va_copy(tmp, ap);
        sum += va_arg(tmp, int);
        va_arg(ap, int); 
        va_end(tmp);
    }
    
    va_end(ap); 
    return sum;
}
