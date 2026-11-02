/* TEST    : comma_45_assign_to_const
 * ERROR   : assignment to a const object inside a comma expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    const int c = 1;
#else
    int c = 1;
#endif
    (void)(0, c = 2);
    return c;
}
