int op1(void) { return 1; }
int op2(void) { return 2; }
int main(void) {
    int (*const fp)(void) = op1;
    fp = op2;
    return 0;
}
