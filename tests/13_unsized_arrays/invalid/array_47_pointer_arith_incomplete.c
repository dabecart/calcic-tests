/* TEST    : array_47_pointer_arith_incomplete
 * ERROR   : pointer arithmetic on pointer to an array of unknown size
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int (*p)[] = 0;
    p = p + 1;
#else
    int (*p)[3] = 0;
    p = p + 1;
#endif
    return p == 0;
}
