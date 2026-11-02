/* TEST    : array_22_string_too_long
 * ERROR   : string literal longer than the array it initializes
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    char s[3] = "abcd";
#else
    char s[4] = "abcd";
#endif
    return s[0];
}
