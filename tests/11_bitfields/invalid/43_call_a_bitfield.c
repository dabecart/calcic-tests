/*
 * INVALID TEST: call_a_bitfield
 * Operator applied to an operand of the wrong type (a bit-field is an integer).
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
int main(void)
{
    struct S s = {1};
    return s.a(1);
}
