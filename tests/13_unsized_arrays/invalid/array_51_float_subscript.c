/* TEST    : array_51_float_subscript
 * ERROR   : array subscript of floating type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int a[] = { 1, 2 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return a[1.5];
#else
    return a[1];
#endif
}
