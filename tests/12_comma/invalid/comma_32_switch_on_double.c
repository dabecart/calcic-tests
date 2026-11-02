/* TEST    : comma_32_switch_on_double
 * ERROR   : switch controlling expression has floating type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    switch ((0, 1.5)) {
#else
    switch ((0, 1)) {
#endif
    default:
        break;
    }
    return 0;
}
