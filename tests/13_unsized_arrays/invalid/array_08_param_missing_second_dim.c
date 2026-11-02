/* TEST    : array_08_param_missing_second_dim
 * ERROR   : array parameter whose element type is incomplete (int m[][])
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
static int f(int m[][]) { return 0; }
#else
static int f(int m[][3]) { return 0; }
#endif
int main(void) { return 0; }
