/*
 * INVALID TEST: address_of_bitfield_nested
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct O { struct I { unsigned y : 4; } in; };
int main(void)
{
    struct O o;
    unsigned *p = &o.in.y;
    return (int)*p;
}
