/* Invalid: Negative bitfield width */
struct S {
    int a : -2; /* Error: negative width in bit-field */
};

int main(void) {
    return 0;
}
