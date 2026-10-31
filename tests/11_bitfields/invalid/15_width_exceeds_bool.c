/*
 * INVALID TEST: width_exceeds_bool
 * C99 6.7.2.1p3: the width shall be an integer constant expression, not exceed the width of the type, and be non-negative (zero only for unnamed fields).
 * _Bool has a width of 1.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { _Bool a : 2; };
int main(void) { struct S s; s.a = 0; return 0; }
