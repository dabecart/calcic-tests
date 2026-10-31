/*
 * INVALID TEST: sizeof_bitfield_unparenthesized
 * C99 6.5.3.4p1: sizeof shall not be applied to a bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
int main(void)
{
    struct S s = {0};
    unsigned long n = sizeof s.a;
    return (int)n;
}
