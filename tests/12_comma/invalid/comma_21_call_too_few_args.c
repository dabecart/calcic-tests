/* TEST    : comma_21_call_too_few_args
 * ERROR   : parenthesized comma makes ONE argument; function expects two
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static int f(int a, int b) { return a + b; }
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return f((1, 2));
#else
    return f(1, 2);
#endif
}
