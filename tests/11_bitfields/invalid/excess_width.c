/* Invalid: Bitfield width exceeds underlying type width */
struct S {
    int a : 65; /* Error: width of 'a' exceeds its type */
};

int main(void) {
    return 0;
}
