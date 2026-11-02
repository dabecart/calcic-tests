/* TEST    : array_53_static_inner_param_dim
 * ERROR   : 'static' in a non-outermost parameter array declarator
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
static int f(int a[2][static 3]) { return a[0][0]; }
#else
static int f(int a[static 2][3]) { return a[0][0]; }
#endif
int main(void) { return 0; }
