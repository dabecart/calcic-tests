/* TEST    : array_05_block_extern_with_init
 * ERROR   : block-scope extern declaration with an initializer
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    extern int e[] = { 1, 2 };
#else
    extern int e[];
#endif
    return 0;
}
