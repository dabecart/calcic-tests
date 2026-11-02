/* TEST    : array_43_extern_conflicting_size
 * ERROR   : two extern declarations with different sizes
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
extern int e[3];
#ifndef FIXED
/* >>> the single intentional error is below <<< */
extern int e[4];
#else
extern int e[3];
#endif
int main(void) { return 0; }
