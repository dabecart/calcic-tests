/* TEST    : comma_28_int_to_pointer_init
 * ERROR   : initializing a pointer from an int comma expression without a cast
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int *p = (0, 0);
#else
    int *p = (int *)(0, 0);
#endif
    return p == 0;
}
