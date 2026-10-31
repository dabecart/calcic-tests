/*
 * INVALID TEST: struct_typed_bitfield
 * C99 6.7.2.1p3: a bit-field shall have type _Bool, signed int, unsigned int (or an implementation-defined integer type).
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct In { int x; };
struct S { struct In v : 3; };
int main(void) { return 0; }
