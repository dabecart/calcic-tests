/* TEST    : comma_16_double_comma
 * ERROR   : syntax error: two consecutive commas
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (1,, 2);
#else
    int x = (1, 2);
#endif
    return x;
}
