/* TEST    : comma_05_array_size_file_scope
 * ERROR   : comma operator in a constant expression (array size at file scope)
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
int arr[(1, 2)];
#else
int arr[2];
#endif
int main(void) { return arr[0]; }
