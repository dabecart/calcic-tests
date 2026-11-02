/* TEST    : comma_17_trailing_comma_in_call
 * ERROR   : syntax error: trailing comma in an argument list
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
    return f(1, );
#else
    return f(1);
#endif
}
