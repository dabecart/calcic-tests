// Assigning pointers of two different tagless definitions.
// Each tagless definition creates a unique type.
int main(void) {
    struct { int a; } x;
    struct { int a; } y;
    
    struct { int a; } *px = &x;
    
    /* ERROR: Incompatible pointer types. */
    px = &y; 
    
    return 0;
}
