/* TEST    : array_24_struct_excess_member_init
 * ERROR   : too many initializers for a struct element of an unsized array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
struct pt { int x, y; };
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    struct pt a[] = { { 1, 2, 3 } };
#else
    struct pt a[] = { { 1, 2 } };
#endif
    return a[0].x;
}
