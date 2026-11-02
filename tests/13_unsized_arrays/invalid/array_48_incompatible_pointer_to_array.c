/* TEST    : array_48_incompatible_pointer_to_array
 * ERROR   : pointer to int[2] initialized with address of int[3]
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
int main(void)
{
    int a[] = { 1, 2, 3 };
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int (*p)[2] = &a;
#else
    int (*p)[3] = &a;
#endif
    return (*p)[0];
}
