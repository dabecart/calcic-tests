/* TEST    : comma_34_modulo_on_double
 * ERROR   : operand of % has floating type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (0, 1.5) % 2;
#else
    int x = (0, 3) % 2;
#endif
    return x;
}
