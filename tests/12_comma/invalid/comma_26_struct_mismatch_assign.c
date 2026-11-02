/* TEST    : comma_26_struct_mismatch_assign
 * ERROR   : assigning a comma expression of struct A to an object of struct B
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
struct A { int x; };
struct B { int x; };
int main(void)
{
    struct A a = { 1 }, a2;
    struct B b;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    b = (0, a);
#else
    a2 = (0, a);
#endif
    (void)b;
    (void)a2;
    return 0;
}
