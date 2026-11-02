/* TEST    : array_41_sizeof_incomplete_type
 * ERROR   : sizeof applied to the incomplete type int[]
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int n = sizeof(int[]);
#else
    int n = sizeof(int[3]);
#endif
    return n;
}
