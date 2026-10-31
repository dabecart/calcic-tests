/*
 * INVALID TEST: address_of_bitfield
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; unsigned b : 5; };
int main(void)
{
    struct S s = {1, 2};
    unsigned *p = &s.a;
    return (int)*p;
}
