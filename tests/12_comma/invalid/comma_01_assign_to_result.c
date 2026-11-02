/* TEST    : comma_01_assign_to_result
 * ERROR   : the result of a comma expression is not an lvalue (simple assignment)
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
    (a, b) = 1;
#else
    b = 1;
#endif
    return a + b;
}
