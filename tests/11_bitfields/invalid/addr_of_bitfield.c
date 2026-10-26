/* Invalid: Taking the address of a bitfield */
struct S {
    unsigned int a : 4;
};

int main(void) {
    struct S s;
    unsigned int *p = &s.a; /* Error: address of bit-field requested */
    return 0;
}
