/* TEST    : array_25_pointer_in_int_init
 * ERROR   : initializing an int element with a string literal (pointer)
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = { "abc" };
#else
    int a[] = { 1 };
#endif
    return a[0];
}
