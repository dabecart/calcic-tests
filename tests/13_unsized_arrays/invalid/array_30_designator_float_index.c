/* TEST    : array_30_designator_float_index
 * ERROR   : array designator of floating type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = { [1.5] = 1 };
#else
    int a[] = { [1] = 1 };
#endif
    return a[1];
}
