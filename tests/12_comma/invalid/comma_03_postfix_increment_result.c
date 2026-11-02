/* TEST    : comma_03_postfix_increment_result
 * ERROR   : operand of ++ must be a modifiable lvalue; a comma expression is not
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int a = 0, b = 0;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    (a, b)++;
#else
    b++;
#endif
    return a + b;
}
