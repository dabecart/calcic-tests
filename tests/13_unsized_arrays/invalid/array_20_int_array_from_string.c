/* TEST    : array_20_int_array_from_string
 * ERROR   : int array initialized from a string literal
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = "abc";
#else
    char a[] = "abc";
#endif
    return a[0];
}
