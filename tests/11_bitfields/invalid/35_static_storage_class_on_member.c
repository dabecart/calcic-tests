/*
 * INVALID TEST: static_storage_class_on_member
 * 6.7.2.1p2: members cannot have a storage-class specifier.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { static unsigned a : 3; };
int main(void) { return 0; }
