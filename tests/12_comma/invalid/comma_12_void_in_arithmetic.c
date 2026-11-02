/* TEST    : comma_12_void_in_arithmetic
 * ERROR   : a void comma expression used as an arithmetic operand
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = 1 + (0, (void)0);
#else
    int x = 1 + (0, 0);
#endif
    return x;
}
