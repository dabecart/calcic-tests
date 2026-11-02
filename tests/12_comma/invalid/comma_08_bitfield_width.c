/* TEST    : comma_08_bitfield_width
 * ERROR   : comma operator in a constant expression (bit-field width)
 *
 * This file contains exactly ONE error; a conforming compiler must
 * reject it.  Compile with -DFIXED to obtain the corrected (valid)
 * version of the same file, used as a control.
 */
struct S {
#ifndef FIXED
/* >>> the single intentional error is below <<< */
    int f : (1, 2);
#else
    int f : 2;
#endif
};
int main(void) { struct S s; s.f = 1; return s.f; }
