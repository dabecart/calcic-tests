/*
 * INVALID TEST: address_of_bitfield_as_argument
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
static void take(unsigned *p) { *p = 1; }
int main(void)
{
    struct S s = {0};
    take(&s.a);
    return 0;
}
