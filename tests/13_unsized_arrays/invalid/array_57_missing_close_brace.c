/* TEST    : array_57_missing_close_brace
 * ERROR   : syntax error: missing '}' in initializer
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = { 1, 2;
#else
    int a[] = { 1, 2 };
#endif
    return a[0];
}
