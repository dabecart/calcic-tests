// Passing a struct defined inline to a function expecting a typedef.
// Even if members match, they are incompatible types.
typedef struct { int x; } TypeA;

void func(TypeA a) {}

int main(void) {
    /* Define a new tagless struct with identical layout */
    struct { int x; } var = { 1 };
    
    /* ERROR: Incompatible types. 'var' is not 'TypeA'. */
    func(var); 
    
    return 0;
}
