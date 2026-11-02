/* TEST    : comma_36_pointer_plus_pointer
 * ERROR   : adding two pointers
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int v = 0;
    int *p = &v, *q = &v;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int *r = (0, p) + (0, q);
#else
    int *r = (0, p) + (0, 1);
#endif
    return *r;
}
