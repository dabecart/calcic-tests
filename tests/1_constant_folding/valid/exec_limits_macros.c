// Exit code: 0

/* Tests usage of <limits.h> macros in constant folding */
#include <limits.h>

/* These should be folded at compile time */
int max_i = INT_MAX;
int min_i = INT_MIN;
unsigned int max_u = UINT_MAX;

/* Calculation checks */
int check1 = INT_MAX + 0;
unsigned int check2 = UINT_MAX - 0;

int main() {
    /* Basic sanity checks */
    if (max_i < 0) return 1; /* INT_MAX must be positive */
    if (min_i > 0) return 2; /* INT_MIN must be negative */
    
    /* Verify wrapping logic matches constants */
    /* UINT_MAX + 1 should be 0 */
    if (max_u + 1 != 0) return 3;
    
    return 0;
}