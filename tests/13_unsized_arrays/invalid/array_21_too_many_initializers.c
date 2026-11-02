/* TEST    : array_21_too_many_initializers
 * ERROR   : excess elements in array initializer
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[2] = { 1, 2, 3 };
#else
    int a[2] = { 1, 2 };
#endif
    return a[0];
}
