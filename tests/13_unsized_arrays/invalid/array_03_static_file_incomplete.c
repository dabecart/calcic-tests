/* TEST    : array_03_static_file_incomplete
 * ERROR   : file-scope static (internal linkage) tentative definition of incomplete array
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
#ifndef FIXED
/* >>> the single intentional error is below <<< */
static int a[];
#else
static int a[] = { 1 };
#endif
int main(void) { return 0; }
