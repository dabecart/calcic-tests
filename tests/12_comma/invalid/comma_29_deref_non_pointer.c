/* TEST    : comma_29_deref_non_pointer
 * ERROR   : indirection applied to an int comma expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int y = 3;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = *(1, 2);
#else
    int x = *(1, &y);
#endif
    return x;
}
