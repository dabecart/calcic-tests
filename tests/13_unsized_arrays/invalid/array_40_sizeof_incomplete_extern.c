/* TEST    : array_40_sizeof_incomplete_extern
 * ERROR   : sizeof applied to an extern array of unknown size
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
extern int e[];
#else
extern int e[3];
#endif
int n = sizeof(e);
int main(void) { return n; }
