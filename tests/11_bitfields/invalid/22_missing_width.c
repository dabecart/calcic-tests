/*
 * INVALID TEST: missing_width
 * A colon must be followed by a constant expression.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : ; };
int main(void) { return 0; }
