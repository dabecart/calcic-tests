/* Valid: Accessing and modifying bitfield structs via pointers */
struct S {
    unsigned int a : 4;
};

int main(void) {
    struct S s;
    struct S *p = &s;
    p->a = 12;
    if (s.a != 12) return 1;
    return 0;
}
