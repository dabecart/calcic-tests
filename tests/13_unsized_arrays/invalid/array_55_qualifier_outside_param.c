/* TEST    : array_55_qualifier_outside_param
 * ERROR   : type qualifier inside array brackets outside a function parameter
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[const 3];
#else
    int a[3];
#endif
    return 0;
}
