int inner(void) { return 0; }
int (outer(void))(void) {
    return inner;
}
int main(void) {
    return 0;
}
