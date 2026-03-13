// Exit code: 0
#include <stdarg.h>
int sum_all(int count, ...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    for(int i=0; i<count; i++) sum += va_arg(args, int);
    va_end(args);
    return sum;
}
int main(void) {
    int (*v_op)(int, ...) = sum_all;
    int val = v_op(3, 10, 20, 30);
    if(val != 60) return 113;
    return 0;
}
