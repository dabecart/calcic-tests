#include <stdarg.h>

void f(int a, ...) { 
    va_list ap; 
    va_start(ap, a); 
    va_arg(ap, int[3]); 
}

int main(){
    return 0;
}
