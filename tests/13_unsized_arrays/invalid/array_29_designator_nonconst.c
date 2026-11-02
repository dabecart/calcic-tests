/* TEST    : array_29_designator_nonconst
 * ERROR   : non-constant array designator
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int i = 1;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = { [i] = 1 };
#else
    int a[] = { [1] = 1 };
#endif
    return a[1] + i;
}
