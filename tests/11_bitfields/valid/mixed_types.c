/* Valid: Mixed base types (char, short, int) */
struct S {
    unsigned char a : 3;
    unsigned short b : 10;
    unsigned int c : 5;
};

int main(void) {
    struct S s;
    s.a = 5;
    s.b = 500;
    s.c = 15;

    if (s.a != 5) return 1;
    if (s.b != 500) return 2;
    if (s.c != 15) return 3;
    return 0;
}
