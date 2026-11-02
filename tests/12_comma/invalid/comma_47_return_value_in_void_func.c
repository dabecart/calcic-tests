/* TEST    : comma_47_return_value_in_void_func
 * ERROR   : returning a value (comma expression) from a void function
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static void f(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return (1, 2);
#else
    (void)(1, 2);
    return;
#endif
}
int main(void) { f(); return 0; }
