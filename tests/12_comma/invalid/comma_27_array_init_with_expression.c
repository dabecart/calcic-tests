/* TEST    : comma_27_array_init_with_expression
 * ERROR   : an array cannot be initialized by a (parenthesized) expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[2] = (1, 2);
#else
    int a[2] = { (1, 2), 3 };
#endif
    return a[0];
}
