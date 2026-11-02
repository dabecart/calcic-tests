/* TEST    : array_12_array_of_functions
 * ERROR   : array of functions
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
int fa[3](void);
#else
int (*fa[3])(void);
#endif
int main(void) { return 0; }
