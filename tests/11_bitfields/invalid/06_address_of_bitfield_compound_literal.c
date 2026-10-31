/*
 * INVALID TEST: address_of_bitfield_compound_literal
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
int main(void)
{
    unsigned *p = &(struct S){1}.a;
    return (int)*p;
}
