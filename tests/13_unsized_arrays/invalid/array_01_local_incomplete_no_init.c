/* TEST    : array_01_local_incomplete_no_init
 * ERROR   : local array of unknown size without initializer
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a[];
#else
    int a[1];
#endif
    return 0;
}
