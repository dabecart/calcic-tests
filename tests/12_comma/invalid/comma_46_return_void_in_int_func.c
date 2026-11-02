/* TEST    : comma_46_return_void_in_int_func
 * ERROR   : returning a void comma expression from an int function
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static int f(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    return (1, (void)0);
#else
    return (1, 0);
#endif
}
int main(void) { return f(); }
