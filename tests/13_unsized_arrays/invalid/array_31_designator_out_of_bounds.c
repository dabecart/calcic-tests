/* TEST    : array_31_designator_out_of_bounds
 * ERROR   : designator index beyond the bounds of a sized array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[3] = { [3] = 1 };
#else
    int a[3] = { [2] = 1 };
#endif
    return a[2];
}
