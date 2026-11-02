/* TEST    : array_35_assign_array
 * ERROR   : assignment to an array object
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int a[] = { 1, 2 };
    int b[2];
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    b = a;
#else
    b[0] = a[0];
#endif
    return b[0];
}
