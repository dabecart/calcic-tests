// Exit code: 0
// A named struct defined *inside* a tagless struct has scope 
// of the enclosing block (or file). It is NOT private to the struct.

typedef struct {
    struct InnerTag { int code; } inner;
    int y;
} Wrapper;

int main(void) {
    Wrapper w;
    w.inner.code = 55;

    /* 'struct InnerTag' should be visible here per C99 6.2.1 */
    struct InnerTag independent_var;
    independent_var.code = 66;

    if (w.inner.code != 55) return 1;
    if (independent_var.code != 66) return 2;

    return 0;
}
