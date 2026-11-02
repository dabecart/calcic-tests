/* TEST    : array_14_zero_size
 * ERROR   : array of size zero
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[0];
#else
    int a[1];
#endif
    return 0;
}
