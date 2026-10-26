/* Valid: Integer promotions in bitfield expressions */
struct S {
    unsigned int a : 4;
    unsigned int b : 4;
};

int main(void) {
    struct S s;
    s.a = 10;
    s.b = 5;
    unsigned int res = s.a + s.b;
    if (res != 15) return 1;
    return 0;
}
