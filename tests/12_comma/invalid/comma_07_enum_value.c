/* TEST    : comma_07_enum_value
 * ERROR   : comma operator in a constant expression (enumerator value)
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
enum { A = (1, 2) };
#else
enum { A = 2 };
#endif
int main(void) { return A; }
