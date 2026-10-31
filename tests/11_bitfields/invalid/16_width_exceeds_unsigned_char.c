/*
 * INVALID TEST: width_exceeds_unsigned_char
 * C99 6.7.2.1p3: the width shall be an integer constant expression, not exceed the width of the type, and be non-negative (zero only for unnamed fields).
 * unsigned char is implementation-defined as a bit-field type; rejecting the type altogether is also acceptable.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned char a : 9; };
int main(void) { struct S s; s.a = 0; return 0; }
