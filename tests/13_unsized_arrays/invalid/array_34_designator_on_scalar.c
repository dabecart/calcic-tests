/* TEST    : array_34_designator_on_scalar
 * ERROR   : array designator used to initialize a scalar
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = { [0] = 1 };
#else
    int x = { 1 };
#endif
    return x;
}
