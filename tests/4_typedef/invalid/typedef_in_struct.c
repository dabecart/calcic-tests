int main(void) {
    struct S {
        typedef int InnerT; // The typedef storage class cannot be used here.
        InnerT x;
    };
    struct S s;
    s.x = 10;
    if (s.x != 10) return 1;
    return 0;
}