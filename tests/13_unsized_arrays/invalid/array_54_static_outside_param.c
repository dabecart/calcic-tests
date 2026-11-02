/* TEST    : array_54_static_outside_param
 * ERROR   : 'static' inside array brackets outside a function parameter
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[static 3] = { 1, 2, 3 };
#else
    int a[3] = { 1, 2, 3 };
#endif
    return a[0];
}
