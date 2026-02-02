// Exit code: 0

int main() {
    int x = 5;
    int y = 10;

    /* 1. Pointer to Const (const int *) */
    /* Can change pointer, cannot change data via pointer */
    const int *p1 = &x;
    if (*p1 != 5) return 1;
    
    p1 = &y; /* Valid: Pointer itself is not const */
    if (*p1 != 10) return 2;

    /* 2. Const Pointer (int * const) */
    /* Cannot change pointer, CAN change data */
    int * const p2 = &x;
    *p2 = 20; /* Valid: Data is mutable */
    if (x != 20) return 3;

    /* 3. Const Pointer to Const (const int * const) */
    /* Locked down completely, but reading is fine */
    const int * const p3 = &y;
    int val = *p3;
    if (val != 10) return 4;

    return 0;
}