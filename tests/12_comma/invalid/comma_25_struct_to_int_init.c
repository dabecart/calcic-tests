/* TEST    : comma_25_struct_to_int_init
 * ERROR   : initializing an int with a struct-valued comma expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
struct pt { int x, y; };
int main(void)
{
    struct pt s = { 1, 2 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int x = (0, s);
#else
    int x = (0, s.x);
#endif
    return x;
}
