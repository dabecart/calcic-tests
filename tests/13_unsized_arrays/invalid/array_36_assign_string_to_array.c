/* TEST    : array_36_assign_string_to_array
 * ERROR   : assigning a string literal to a char array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    char s[] = "ab";
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    s = "cd";
#else
    s[0] = 'c';
#endif
    return s[0];
}
