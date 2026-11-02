/* TEST    : array_42_sizeof_incomplete_2d_type
 * ERROR   : sizeof applied to the incomplete type int[][3]
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int n = sizeof(int[][3]);
#else
    int n = sizeof(int[2][3]);
#endif
    return n;
}
