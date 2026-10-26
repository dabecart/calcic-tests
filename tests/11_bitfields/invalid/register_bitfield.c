/* Invalid: Register storage class specifier for bitfield */
struct S {
    register int a : 3; /* Error: illegal storage class for bit-field */
};

int main(void) {
    return 0;
}
