/* TEST    : array_38_increment_array
 * ERROR   : increment applied to an array object
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int a[] = { 1, 2 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    a++;
#else
    a[0]++;
#endif
    return a[0];
}
