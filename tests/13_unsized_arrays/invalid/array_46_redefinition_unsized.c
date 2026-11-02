/* TEST    : array_46_redefinition_unsized
 * ERROR   : two definitions of the same unsized array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int a[] = { 1 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
int a[] = { 1, 2 };
#else
extern int a[];
#endif
int main(void) { return a[0]; }
