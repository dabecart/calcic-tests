/*
 * INVALID TEST: address_of_bitfield_offsetof_style
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 * Hand-written offsetof applied to a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; unsigned b : 5; };
int main(void)
{
    unsigned long off = (unsigned long)&((struct S *)0)->b;
    return (int)off;
}
