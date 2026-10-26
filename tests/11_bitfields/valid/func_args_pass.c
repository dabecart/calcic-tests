/* Valid: Passing bitfield structs as function arguments */
struct S {
    unsigned int a : 5;
    unsigned int b : 3;
};

int check_struct(struct S s) {
    if (s.a != 15) return 1;
    if (s.b != 5) return 2;
    return 0;
}

int main(void) {
    struct S s;
    s.a = 15;
    s.b = 5;
    return check_struct(s);
}
