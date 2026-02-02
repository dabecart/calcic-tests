// Exit code: 0

int main() {
    const int x = 5;
    const int y = 10;

    /* 1. Pointer to Const (const int *) */
    /* Can change pointer, cannot change data via pointer */
    const int *p1 = &x;
    if (*p1 != 5) return 1;
    
    p1 = &y; /* Valid: Pointer itself is not const */
    if (*p1 != 10) return 2;

    const int * const p2 = &x;
    if (*p2 != 5) return 3;
    
    const int * const p3 = &y;
    if (*p3 != 10) return 4;

    /* 2. Const Pointer to Const (const int * const) */
    /* Locked down completely, but reading is fine */
    const int * const p4 = &y;
    int val = *p4;
    if (val != 10) return 5;

    return 0;
}