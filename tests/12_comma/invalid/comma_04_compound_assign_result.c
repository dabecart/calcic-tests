/* TEST    : comma_04_compound_assign_result
 * ERROR   : left operand of += must be a modifiable lvalue; a comma expression is not
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
    (a, b) += 2;
#else
    b += 2;
#endif
    return a + b;
}
