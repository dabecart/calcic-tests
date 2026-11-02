/* TEST    : comma_23_macro_too_many_args
 * ERROR   : macro takes one argument but the unparenthesized comma gives two
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#define ID(x) (x)
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return ID(1, 2);
#else
    return ID((1, 2));
#endif
}
