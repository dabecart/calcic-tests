/* Invalid: Array of bitfields */
struct S {
    int a[5] : 2; /* Error: array of bit-fields */
};

int main(void) {
    return 0;
}
