/* TEST    : comma_42_type_name_as_operand
 * ERROR   : a type name is not an expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (1, int);
#else
    int x = (1, 2);
#endif
    return x;
}
