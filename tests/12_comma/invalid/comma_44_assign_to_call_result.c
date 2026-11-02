/* TEST    : comma_44_assign_to_call_result
 * ERROR   : assignment to the result of a function call (right side of a comma)
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static int f(void) { return 1; }
int main(void)
{
    int a = 0, b = 0;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    a, f() = 1;
#else
    a, b = 1;
#endif
    return a + b;
}
