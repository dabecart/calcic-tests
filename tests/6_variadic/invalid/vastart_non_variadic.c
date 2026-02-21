#include <stdarg.h>
void f(int a) { 
    va_list ap; 
    va_start(ap, a); 
}

int main(){
    return 0;
}
