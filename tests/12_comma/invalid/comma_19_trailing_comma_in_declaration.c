/* TEST    : comma_19_trailing_comma_in_declaration
 * ERROR   : syntax error: dangling comma in a declarator list
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int a = 1, ;
#else
    int a = 1;
#endif
    return a;
}
