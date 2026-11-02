/* TEST    : array_09_param_unsized_inner_dim
 * ERROR   : array parameter int m[2][] : incomplete element type
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
static int f(int m[2][]) { return 0; }
#else
static int f(int m[2][3]) { return 0; }
#endif
int main(void) { return 0; }
