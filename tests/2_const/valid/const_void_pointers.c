// Exit code: 0

int main() {
    int x = 5;
    const int cx = 10;

    /* 1. int* -> void* (Implicit: Valid) */
    void *vp = &x; 
    
    /* 2. const int* -> const void* (Implicit: Valid) */
    /* Adding low-level const to void is safe */
    const void *cvp = &cx;

    /* 3. int* -> void* const (Implicit: Valid) */
    /* Top-level const on destination is fine for initialization */
    void * const vpc = &x;

    /* 4. Any pointer -> const void* (Implicit: Valid) */
    const void *cvp2 = &x; 

    /* 5. Casting back (Explicit casts override const) */
    const int *c_ptr = (const int *)cvp;
    if (*c_ptr != 10) return 1;

    return 0;
}