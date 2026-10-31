/*
 * INVALID TEST: duplicate_member_name
 * 6.7.2.1p3: member names within a struct must be distinct (also between bit-fields).
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; unsigned a : 4; };
int main(void) { return 0; }
