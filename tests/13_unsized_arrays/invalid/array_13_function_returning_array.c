/* TEST    : array_13_function_returning_array
 * ERROR   : function returning an array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
int f(void)[3];
#else
int (*f(void))[3];
#endif
int main(void) { return 0; }
