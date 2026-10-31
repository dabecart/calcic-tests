/*
 * INVALID TEST: named_zero_width
 * C99 6.7.2.1p3: the width shall be an integer constant expression, not exceed the width of the 
 * type, and be non-negative (zero only for unnamed fields).
 * A zero-width bit-field shall not have a declarator.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 0; unsigned b : 3; };
int main(void) { struct S s; s.b = 0; return 0; }
