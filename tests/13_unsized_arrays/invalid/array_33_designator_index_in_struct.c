/* TEST    : array_33_designator_index_in_struct
 * ERROR   : array designator used in a struct initializer
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
    struct pt p = { [0] = 1 };
#else
    struct pt p = { .x = 1 };
#endif
    return p.x;
}
