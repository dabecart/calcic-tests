/* TEST    : array_39_modify_const_array
 * ERROR   : assignment to an element of a const array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    const int a[] = { 1, 2 };
#else
    int a[] = { 1, 2 };
#endif
    a[0] = 3;
    return a[0];
}
