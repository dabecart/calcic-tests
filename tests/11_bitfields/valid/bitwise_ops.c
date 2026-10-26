/* Valid: Bitwise operations on bitfields */
struct S {
    unsigned int a : 4;
};

int main(void) {
    struct S s;
    s.a = 0x5;
    s.a = s.a ^ 0xF;
    if (s.a != 0xA) return 1;
    return 0;
}
