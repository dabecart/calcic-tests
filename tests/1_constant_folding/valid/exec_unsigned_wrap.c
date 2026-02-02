// Exit code: 0

/* Tests well-defined unsigned integer wraparound behavior */
/* Defined behavior: Unsigned arithmetic is modulo 2^N */
unsigned int u1 = -1;                /* UINT_MAX */
unsigned int u2 = 0U - 1U;           /* UINT_MAX */
/* We use explicit constants to avoid assumptions about size, 
   but for this test assuming 32-bit int logic for the check logic */
unsigned int u3 = (unsigned int)4294967295U + 1; /* Should wrap to 0 */

int main() {
    /* Verify u1 is largest possible uint */
    if (u1 + 1 != 0) return 1; 
    if (u2 + 1 != 0) return 2;
    if (u3 != 0) return 3;
    return 0;
}