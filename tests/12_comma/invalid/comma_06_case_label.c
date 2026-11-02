/* TEST    : comma_06_case_label
 * ERROR   : comma operator in a constant expression (case label)
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int x = 2;
    switch (x) {
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    case (1, 2):
#else
    case 2:
#endif
        break;
    default:
        break;
    }
    return 0;
}
