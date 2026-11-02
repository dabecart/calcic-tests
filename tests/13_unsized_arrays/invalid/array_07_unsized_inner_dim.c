/* TEST    : array_07_unsized_inner_dim
 * ERROR   : int m[2][] : element type is incomplete
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int m[2][] = { { 1 }, { 2 } };
#else
    int m[2][1] = { { 1 }, { 2 } };
#endif
    return m[0][0];
}
