/* TEST    : comma_38_for_commas_for_semicolons
 * ERROR   : commas used instead of semicolons in a for header
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int i;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    for (i = 0, i < 3, i++)
#else
    for (i = 0; i < 3; i++)
#endif
        ;
    return i;
}
