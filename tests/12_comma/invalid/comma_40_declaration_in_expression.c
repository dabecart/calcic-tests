/* TEST    : comma_40_declaration_in_expression
 * ERROR   : a declaration cannot appear as an operand of the comma operator
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (int y = 1, 2);
#else
    int y;
    int x = (y = 1, 2);
#endif
    return x + y;
}
