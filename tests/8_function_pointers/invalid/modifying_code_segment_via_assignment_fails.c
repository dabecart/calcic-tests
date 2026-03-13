int dummy(void) { return 0; }
int main(void) {
    int (*fp)(void) = dummy;
    *fp = 5;
    return 0;
}
