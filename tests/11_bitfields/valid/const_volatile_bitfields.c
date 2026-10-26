/* Valid: const and volatile bitfields */
struct S {
    const unsigned int a : 4;
    volatile unsigned int b : 4;
};

int main(void) {
    struct S s = { 5, 6 };
    if (s.a != 5) return 1;
    if (s.b != 6) return 2;
    return 0;
}
