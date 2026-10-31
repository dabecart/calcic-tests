/*
 * INVALID TEST: address_of_bitfield_cast_to_integer
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { signed int a : 3; };
int main(void)
{
    struct S s = {0};
    long l = (long)&s.a;
    return (int)l;
}
