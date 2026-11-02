/* TEST    : comma_13_void_call_as_result
 * ERROR   : the right operand is a call to a void function and its value is used
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static void g(void) { }
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (0, g());
#else
    int x = (g(), 0);
#endif
    return x;
}
