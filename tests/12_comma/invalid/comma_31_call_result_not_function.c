/* TEST    : comma_31_call_result_not_function
 * ERROR   : calling a comma expression whose value is an int
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
static int twice(int v) { return v * 2; }
int main(void)
{
    int (*fp)(int) = twice;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (1, 2)(3);
#else
    int x = (1, fp)(3);
#endif
    return x;
}
