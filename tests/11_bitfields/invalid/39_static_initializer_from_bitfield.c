/*
 * INVALID TEST: static_initializer_from_bitfield
 * A bit-field value is not a constant expression.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
struct S g = {3};
static unsigned x = g.a;
int main(void) { return (int)x; }
