/* TEST    : array_26_nonconst_static_init
 * ERROR   : static array initialized with a non-constant expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int v = 1;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    static int a[] = { v };
#else
    static int a[] = { 1 };
#endif
    return a[0] + v;
}
