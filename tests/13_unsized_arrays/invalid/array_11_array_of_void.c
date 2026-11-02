/* TEST    : array_11_array_of_void
 * ERROR   : array of void
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
extern void v[];
#else
extern void *v[];
#endif
int main(void) { return 0; }
