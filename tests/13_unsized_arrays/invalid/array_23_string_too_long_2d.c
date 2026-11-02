/* TEST    : array_23_string_too_long_2d
 * ERROR   : string literal too long for a row of a 2D char array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    char s[][2] = { "abc" };
#else
    char s[][4] = { "abc" };
#endif
    return s[0][0];
}
