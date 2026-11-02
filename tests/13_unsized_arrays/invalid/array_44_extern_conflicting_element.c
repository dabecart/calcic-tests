/* TEST    : array_44_extern_conflicting_element
 * ERROR   : two extern declarations with different element types
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
extern int e[];
#ifndef FIXED
/* >>> the single intentional error is below <<< */
extern char e[];
#else
extern int e[];
#endif
int main(void) { return 0; }
