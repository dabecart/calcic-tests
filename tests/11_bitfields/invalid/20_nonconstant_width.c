/*
 * INVALID TEST: nonconstant_width
 * C99 6.7.2.1p3: the width shall be an integer constant expression, not exceed the width of the type, and be non-negative (zero only for unnamed fields).
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
int main(void)
{
    int n = 3;
    struct S { unsigned a : n; } s;
    s.a = 1;
    return 0;
}
