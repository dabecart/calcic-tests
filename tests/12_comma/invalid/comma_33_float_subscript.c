/* TEST    : comma_33_float_subscript
 * ERROR   : array subscript has floating type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int a[3] = { 1, 2, 3 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return a[(0, 1.5)];
#else
    return a[(0, 1)];
#endif
}
