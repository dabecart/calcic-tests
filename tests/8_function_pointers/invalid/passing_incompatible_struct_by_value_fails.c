struct A { int x; };
struct B { int x; };
int take_A(struct A a) { return a.x; }
int main(void) {
    int (*fp)(struct B) = take_A;
    return 0;
}
