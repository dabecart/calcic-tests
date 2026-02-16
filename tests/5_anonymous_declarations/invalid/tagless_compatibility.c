// Two tagless structs with identical members are NOT compatible types in C99.
// Assigning a pointer from one to the other must fail.

int main(void) {
    /* Tagless struct A */
    struct {
        int x;
        int y;
    } s1;

    /* Tagless struct B (Identical layout, but different type) */
    struct {
        int x;
        int y;
    } s2;

    struct { int x; int y; } *p1;
    
    p1 = &s1; /* Valid: exact type match (compiler treats definition as unique) */
    
    /* ERROR: Incompatible pointer types. 
       The compiler must treat the type of s1 and s2 as distinct. */
    p1 = &s2; 

    return 0;
}
