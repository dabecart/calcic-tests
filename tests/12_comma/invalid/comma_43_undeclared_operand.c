/* TEST    : comma_43_undeclared_operand
 * ERROR   : use of an undeclared identifier as left operand
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (undeclared_name, 1);
#else
    int x = (0, 1);
#endif
    return x;
}
