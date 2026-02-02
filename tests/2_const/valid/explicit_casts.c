// Exit code: 0

int main() {
    int x = 10;
    const int *p = &x;

    /* 1. Explicitly casting away const */
    /* Compiler MUST allow this (C99 6.5.4) */
    int *mutable_p = (int *)p;
    
    *mutable_p = 20; /* Modifying x through the cast pointer */
    if (x != 20) return 1;

    /* 2. Casting const pointer to void* */
    void *vp = (void *)p; /* Discards const, valid with explicit cast */
    
    /* 3. Casting back */
    int *p2 = (int *)vp;
    *p2 = 30;
    if (x != 30) return 2;

    return 0;
}