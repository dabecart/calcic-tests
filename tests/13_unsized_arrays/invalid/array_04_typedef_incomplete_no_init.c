/* TEST    : array_04_typedef_incomplete_no_init
 * ERROR   : object of typedef'd incomplete array type without initializer
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
typedef int Arr[];
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    Arr a;
#else
    Arr a = { 1 };
#endif
    return a[0];
}
