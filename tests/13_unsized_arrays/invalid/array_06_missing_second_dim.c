/* TEST    : array_06_missing_second_dim
 * ERROR   : int m[][] : element type is incomplete
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int m[][] = { { 1 } };
#else
    int m[][1] = { { 1 } };
#endif
    return m[0][0];
}
