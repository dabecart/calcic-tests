/* TEST    : comma_35_bitnot_on_pointer
 * ERROR   : operand of ~ has pointer type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int x = 1;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int y = ~(0, &x);
#else
    int y = ~(0, x);
#endif
    return y;
}
