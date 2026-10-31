/*
 * INVALID TEST: address_of_bitfield_in_union
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
union U { struct { unsigned a : 3; } f; unsigned raw; };
int main(void)
{
    union U u;
    unsigned *p = &u.f.a;
    return (int)*p;
}
