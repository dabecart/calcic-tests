#include <stdarg.h>

void f(int a, ...) { 
    va_list ap; 
    va_start(ap, a); 
    va_arg(ap, void); 
}

int main(){
    return 0;
}
