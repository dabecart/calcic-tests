/* Valid: Zero-width bitfield alignment boundary reset */
struct S {
    unsigned char a : 3;
    unsigned char : 0;
    unsigned char b : 3;
};

int main(void) {
    struct S s;
    s.a = 5;
    s.b = 6;
    if (s.a != 5) return 1;
    if (s.b != 6) return 2;
    return 0;
}
