/* TEST    : array_37_row_assignment
 * ERROR   : assignment to a row (array) of a 2D array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int m[][2] = { { 1, 2 }, { 3, 4 } };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    m[0] = m[1];
#else
    m[0][0] = m[1][0];
#endif
    return m[0][0];
}
