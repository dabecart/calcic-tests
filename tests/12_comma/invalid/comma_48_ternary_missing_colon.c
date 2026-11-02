/* TEST    : comma_48_ternary_missing_colon
 * ERROR   : syntax error: conditional operator without ':'
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = 1 ? (1, 2);
#else
    int x = 1 ? (1, 2) : 3;
#endif
    return x;
}
