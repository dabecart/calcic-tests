/* TEST    : comma_37_struct_as_condition
 * ERROR   : struct value used where a scalar is required (if condition)
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
    if ((0, s))
#else
    if ((0, s.x))
#endif
        return 1;
    return 0;
}
