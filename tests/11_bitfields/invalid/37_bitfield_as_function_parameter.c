/*
 * INVALID TEST: bitfield_as_function_parameter
 * A bit-field declarator is only allowed inside a struct or union declaration.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
static void f(unsigned a : 3) { (void)a; }
int main(void) { return 0; }
