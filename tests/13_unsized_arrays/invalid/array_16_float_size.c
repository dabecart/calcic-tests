/* TEST    : array_16_float_size
 * ERROR   : array size of floating type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[2.5];
#else
    int a[2];
#endif
    return 0;
}
