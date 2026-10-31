/*
 * INVALID TEST: assign_to_const_qualified_bitfield
 * 6.5.16p2: the left operand of an assignment shall be a modifiable lvalue.
 * NOTE: gcc 13 wrongly ACCEPTS this (it ignores const on bit-field members), so it is
 * expected to FAIL under gcc; a conforming compiler must reject it.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { const unsigned a : 3; };
int main(void)
{
    struct S s = {1};
    s.a = 2;
    return 0;
}
