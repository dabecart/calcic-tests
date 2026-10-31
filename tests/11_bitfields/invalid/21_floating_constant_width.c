/*
 * INVALID TEST: floating_constant_width
 * C99 6.7.2.1p3: the width shall be an integer constant expression, not exceed the width of the type, and be non-negative (zero only for unnamed fields).
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 2.5; };
int main(void) { struct S s; s.a = 0; return 0; }
