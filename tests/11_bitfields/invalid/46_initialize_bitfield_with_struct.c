/*
 * INVALID TEST: initialize_bitfield_with_struct
 * 6.7.8: a bit-field cannot be initialised with a struct value.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct T { int x; };
struct S { unsigned a : 3; };
int main(void)
{
    struct T t = {1};
    struct S s = { t };
    return (int)s.a;
}
