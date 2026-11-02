/* TEST    : comma_11_void_init_int
 * ERROR   : initializing an int with a void comma expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = ((void)0, (void)0);
#else
    int x = ((void)0, 0);
#endif
    return x;
}
