/* TEST    : comma_39_unbalanced_paren
 * ERROR   : syntax error: missing closing parenthesis
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (1, 2;
#else
    int x = (1, 2);
#endif
    return x;
}
