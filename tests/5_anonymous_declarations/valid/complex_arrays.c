// Exit code: 0
// Multidimensional arrays of tagless structs and pointer arithmetic.
typedef struct { int val; } Box;

int main(void) {
    Box grid[2][2] = {
        { {1}, {2} },
        { {3}, {4} }
    };

    if (grid[1][0].val != 3) return 1;

    /* Pointer arithmetic on subarrays */
    Box *p = grid[0]; /* Points to {1} */
    p++;              /* Points to {2} */
    if (p->val != 2) return 2;
    
    p += 2;           /* Skips {2} and {3}, points to {4} */
    if (p->val != 4) return 3;

    return 0;
}
