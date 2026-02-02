// Exit code: 0

struct Point { int x; int y; };
union Data { int i; float f; };

int main() {
    /* 1. Const Struct: All members become const */
    const struct Point p = {10, 20};
    if (p.x != 10) return 1;

    /* 2. Copying const struct to non-const struct */
    /* Valid: This is a value copy (Lvalue conversion) */
    struct Point p2 = p; 
    p2.x = 30; /* p2 is mutable */
    if (p2.x != 30) return 2;

    /* 3. Array Decay to Pointer */
    /* const int[] decays to const int* */
    const int arr[3] = {1, 2, 3};
    const int *ptr = arr;
    if (*ptr != 1) return 3;
    if (*(ptr+1) != 2) return 4;

    /* 4. Const Union */
    const union Data u = { 50 };
    if (u.i != 50) return 5;

    return 0;
}