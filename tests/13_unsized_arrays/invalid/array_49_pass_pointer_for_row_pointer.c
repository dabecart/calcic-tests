/* TEST    : array_49_pass_pointer_for_row_pointer
 * ERROR   : passing int * where int (*)[3] is expected
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static int f(int m[][3]) { return m[0][0]; }
int main(void)
{
    int a[] = { 1, 2, 3 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return f(a);
#else
    return f(&a);
#endif
}
