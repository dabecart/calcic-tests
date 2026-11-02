/* TEST    : array_17_empty_initializer
 * ERROR   : empty initializer braces are not valid C99
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = { };
#else
    int a[] = { 0 };
#endif
    return a[0];
}
