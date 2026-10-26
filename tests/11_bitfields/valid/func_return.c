/* Valid: Returning bitfield structs from functions */
struct S {
    unsigned int a : 4;
    unsigned int b : 4;
};

struct S make_struct(void) {
    struct S s;
    s.a = 10;
    s.b = 5;
    return s;
}

int main(void) {
    struct S s = make_struct();
    if (s.a != 10) return 1;
    if (s.b != 5) return 2;
    return 0;
}
