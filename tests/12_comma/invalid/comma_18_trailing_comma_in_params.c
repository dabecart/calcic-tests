/* TEST    : comma_18_trailing_comma_in_params
 * ERROR   : syntax error: trailing comma in a parameter list
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
static int f(int a,) { return a; }
#else
static int f(int a) { return a; }
#endif
int main(void) { return f(1); }
