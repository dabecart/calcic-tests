/* TEST    : array_10_element_incomplete_struct
 * ERROR   : array whose element type is an incomplete struct
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
struct Inc;
extern struct Inc arr[];
#else
struct Inc { int x; };
extern struct Inc arr[];
#endif
int main(void) { return 0; }
