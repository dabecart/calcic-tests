/* TEST    : comma_09_static_local_init
 * ERROR   : initializer of a static object must be constant; comma is not allowed
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    static int s = (1, 2);
#else
    static int s = 2;
#endif
    return s;
}
