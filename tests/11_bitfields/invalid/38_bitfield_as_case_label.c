/*
 * INVALID TEST: bitfield_as_case_label
 * A bit-field value is not a constant expression.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
int main(void)
{
    struct S s = {1};
    int x = 1;
    switch (x) {
    case s.a: return 1;
    default:  return 0;
    }
}
