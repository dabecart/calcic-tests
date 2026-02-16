// Exit code: 0
// Interaction of const with tagless typedefs.
typedef struct { int x; } S;

int main(void) {
    S s_mutable = { 10 };
    const S s_const = { 20 };
    
    /* Pointer to const S */
    const S *p = &s_mutable; 
    
    if (p->x != 10) return 1;
    if (s_const.x != 20) return 2;

    /* Const pointer to mutable S */
    S * const cp = &s_mutable;
    cp->x = 50;
    
    if (s_mutable.x != 50) return 3;

    return 0;
}
