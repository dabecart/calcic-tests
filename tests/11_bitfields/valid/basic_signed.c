/* Valid: Basic signed bitfields sign extension and storage */
struct S {
    signed int a : 3;
    signed int b : 4;
};

int main(void) {
    struct S s;
    s.a = -3;
    s.b = 7;

    if (s.a != -3) return 1;
    if (s.b != 7) return 2;
    return 0;
}
