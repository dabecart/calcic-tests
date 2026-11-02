/* TEST    : array_18_scalar_initializer
 * ERROR   : array initialized with a scalar instead of a brace list
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = 5;
#else
    int a[] = { 5 };
#endif
    return a[0];
}
