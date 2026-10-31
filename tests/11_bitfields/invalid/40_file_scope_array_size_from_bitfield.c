/*
 * INVALID TEST: file_scope_array_size_from_bitfield
 * A bit-field value is not a constant expression.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; };
struct S g = {3};
int arr[g.a];
int main(void) { return 0; }
