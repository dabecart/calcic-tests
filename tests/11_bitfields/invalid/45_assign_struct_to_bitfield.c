/*
 * INVALID TEST: assign_struct_to_bitfield
 * 6.5.16.1: a struct value cannot be assigned to an integer bit-field.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
struct T { int x; };
int main(void)
{
    struct S s = {0};
    struct T t = {1};
    s.a = t;
    return 0;
}
