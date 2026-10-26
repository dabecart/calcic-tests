/* Invalid: Applying sizeof to a bitfield */
struct S {
    unsigned int a : 4;
};

int main(void) {
    struct S test;
    int sz = sizeof(test.a); /* Error: invalid application of 'sizeof' to bit-field */
    return sz;
}
