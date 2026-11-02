/* TEST    : comma_30_member_of_non_struct
 * ERROR   : member access on an int-valued comma expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
struct pt { int x, y; };
int main(void)
{
    struct pt s = { 1, 2 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int v = (0, 5).x;
#else
    int v = (0, s).x;
#endif
    return v;
}
