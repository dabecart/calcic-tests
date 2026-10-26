/* Valid: Compound assignments on bitfields */
struct S {
    unsigned int a : 4;
};

int main(void) {
    struct S s;
    s.a = 2;
    s.a += 3;
    if (s.a != 5) return 1;
    s.a *= 2;
    if (s.a != 10) return 2;
    return 0;
}
