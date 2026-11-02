/* TEST    : array_56_missing_close_bracket
 * ERROR   : syntax error: missing ']'
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[3 = { 1, 2, 3 };
#else
    int a[3] = { 1, 2, 3 };
#endif
    return a[0];
}
