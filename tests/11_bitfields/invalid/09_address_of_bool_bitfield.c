/*
 * INVALID TEST: address_of_bool_bitfield
 * C99 6.5.3.2p1: the operand of unary & shall not be a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { _Bool flag : 1; };
int main(void)
{
    struct S s = {0};
    _Bool *p = &s.flag;
    return *p;
}
