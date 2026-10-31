/*
 * INVALID TEST: address_of_bitfield_through_pointer
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; unsigned b : 5; };
int main(void)
{
    struct S s = {1, 2};
    struct S *ps = &s;
    unsigned *p = &ps->b;
    return (int)*p;
}
