/*
 * INVALID TEST: assign_to_bitfield_of_const_struct
 * 6.5.16p2: the left operand of an assignment shall be a modifiable lvalue.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
int main(void)
{
    const struct S s = {1};
    s.a = 2;
    return 0;
}
