/* TEST    : array_50_compound_literal_to_int
 * ERROR   : initializing an int with an array-valued compound literal
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (int[]){ 1, 2 };
#else
    int x = (int[]){ 1, 2 }[0];
#endif
    return x;
}
