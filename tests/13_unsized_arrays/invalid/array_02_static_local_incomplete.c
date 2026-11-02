/* TEST    : array_02_static_local_incomplete
 * ERROR   : static local array of unknown size without initializer
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    static int a[];
#else
    static int a[] = { 1 };
#endif
    return 0;
}
