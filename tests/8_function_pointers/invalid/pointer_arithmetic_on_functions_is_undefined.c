int dummy(void) { return 0; }
int main(void) {
    int (*fp)(void) = dummy;
    fp++;
    return 0;
}
