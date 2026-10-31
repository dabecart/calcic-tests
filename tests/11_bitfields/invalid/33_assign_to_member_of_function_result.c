/*
 * INVALID TEST: assign_to_member_of_function_result
 * 6.5.16p2: the left operand of an assignment shall be a modifiable lvalue.
 * A function call result is not an lvalue.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
static struct S make(void) { struct S s = {1}; return s; }
int main(void)
{
    make().a = 3;
    return 0;
}
