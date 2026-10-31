/*
 * INVALID TEST: float_bitfield
 * C99 6.7.2.1p3: a bit-field shall have type _Bool, signed int, unsigned int (or an implementation-defined integer type).
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { float f : 3; };
int main(void) { return 0; }
