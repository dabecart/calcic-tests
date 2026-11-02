/* TEST    : comma_02_address_of_result
 * ERROR   : cannot take the address of a comma expression (not an lvalue)
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int a = 0, b = 0;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int *p = &(a, b);
#else
    int *p = &b;
#endif
    return *p + a;
}
