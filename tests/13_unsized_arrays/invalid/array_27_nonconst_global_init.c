/* TEST    : array_27_nonconst_global_init
 * ERROR   : file-scope array initialized with a non-constant expression
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int v = 1;
#ifndef FIXED
/* >>> the single intentional error is below <<< */
int a[] = { v };
#else
int a[] = { 1 };
#endif
int main(void) { return a[0] + v; }
