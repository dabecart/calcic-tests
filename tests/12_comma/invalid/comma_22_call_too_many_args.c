/* TEST    : comma_22_call_too_many_args
 * ERROR   : unparenthesized comma separates arguments; function expects one
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static int f(int a) { return a; }
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return f(1, 2);
#else
    return f((1, 2));
#endif
}
