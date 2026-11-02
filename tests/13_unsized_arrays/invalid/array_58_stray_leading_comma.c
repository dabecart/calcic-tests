/* TEST    : array_58_stray_leading_comma
 * ERROR   : syntax error: leading comma in initializer list
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = { , 1 };
#else
    int a[] = { 1 };
#endif
    return a[0];
}
