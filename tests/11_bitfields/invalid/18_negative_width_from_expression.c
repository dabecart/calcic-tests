/*
 * INVALID TEST: negative_width_from_expression
 * C99 6.7.2.1p3: the width shall be an integer constant expression, not exceed the width of the type, and be non-negative (zero only for unnamed fields).
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { signed int a : 3 - 5; };
int main(void) { struct S s; s.a = 0; return 0; }
