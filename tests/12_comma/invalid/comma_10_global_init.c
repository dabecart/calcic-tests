/* TEST    : comma_10_global_init
 * ERROR   : initializer of a file-scope object must be constant; comma is not allowed
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
int g = (1, 2);
#else
int g = 2;
#endif
int main(void) { return g; }
