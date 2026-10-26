/* Valid: Bitfields spanning multiple storage allocation units */
struct S {
    unsigned int a : 30;
    unsigned int b : 30;
};

int main(void) {
    struct S s;
    s.a = 0x3FFFFFFF;
    s.b = 0x12345678 & 0x3FFFFFFF;
    if (s.a != 0x3FFFFFFF) return 1;
    if (s.b != (0x12345678 & 0x3FFFFFFF)) return 2;
    return 0;
}
