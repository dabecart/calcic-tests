/* Valid: Basic unsigned bitfields assignment and retrieval */
struct S {
    unsigned int a : 3;
    unsigned int b : 5;
    unsigned int c : 8;
};

int main(void) {
    struct S s;
    s.a = 7;
    s.b = 31;
    s.c = 255;

    if (s.a != 7) return 1;
    if (s.b != 31) return 2;
    if (s.c != 255) return 3;
    return 0;
}
