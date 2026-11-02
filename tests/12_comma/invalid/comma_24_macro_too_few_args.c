/* TEST    : comma_24_macro_too_few_args
 * ERROR   : macro takes two arguments but the parenthesized comma gives one
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#define ADD(a, b) ((a) + (b))
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return ADD((1, 2));
#else
    return ADD(1, 2);
#endif
}
