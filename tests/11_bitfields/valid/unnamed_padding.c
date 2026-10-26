/* Valid: Unnamed bitfields for padding */
struct S {
    unsigned int a : 2;
    unsigned int : 4;
    unsigned int b : 2;
};

int main(void) {
    struct S s;
    s.a = 3;
    s.b = 3;
    if (s.a != 3 || s.b != 3) return 1;
    return 0;
}
