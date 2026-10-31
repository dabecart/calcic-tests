/*
 * INVALID TEST: access_nonexistent_member
 * Unnamed bit-fields (and unknown names) cannot be accessed as members.
 *
 * Expected: the compiler MUST reject this file (non-zero exit status).
 */
struct S { unsigned a : 3; unsigned : 5; unsigned b : 3; };
int main(void)
{
    struct S s = {1, 2};
    return (int)s.pad;
}
