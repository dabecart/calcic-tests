/*
 * INVALID TEST: bitfield_outside_struct
 * A bit-field declarator is only allowed inside a struct or union declaration.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
unsigned x : 3;
int main(void) { return 0; }
