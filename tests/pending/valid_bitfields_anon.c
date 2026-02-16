/* TEST: valid_bitfields_anon.c
 * DESC: Tagless struct containing bitfields.
 * Tests packing and value truncation.
 */
typedef struct {
    unsigned int a : 3;
    unsigned int b : 1;
    int signed_val : 4;
} Flags;

int main(void) {
    Flags f;
    f.a = 7; /* Max 3-bit value (111) */
    f.b = 1;
    f.signed_val = -1; 

    if (f.a != 7) return 1;
    
    f.a++; /* Overflow 3 bits -> 0 */
    if (f.a != 0) return 2;

    if (f.b != 1) return 3;
    
    /* 4-bit signed: range -8 to 7. -1 is 1111 */
    if (f.signed_val != -1) return 4;

    return 0;
}
