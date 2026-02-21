#include <stdarg.h>

struct S;

void f(int a, ...) { 
    va_list ap; 
    va_start(ap, a); 
    // struct S is not a complete type, therefore it's invalid.
    struct S s = va_arg(ap, struct S); 
}

struct S {
    int x;
};

int main(){return 0;}
