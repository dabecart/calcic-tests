/* Valid: _Bool bitfields */
struct S {
    _Bool flag1 : 1;
    _Bool flag2 : 1;
};

int main(void) {
    struct S s;
    s.flag1 = 1;
    s.flag2 = 0;
    if (s.flag1 != 1) return 1;
    if (s.flag2 != 0) return 2;
    return 0;
}
