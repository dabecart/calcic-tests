/* TEST    : array_32_designator_field_in_array
 * ERROR   : field designator used in an array initializer
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[] = { .x = 1 };
#else
    int a[] = { [0] = 1 };
#endif
    return a[0];
}
