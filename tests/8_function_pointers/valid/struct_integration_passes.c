// Exit code: 0
struct calculator {
    int state;
    int (*apply)(int, int);
};
int sub(int a, int b) { return a - b; }
int main(void) {
    struct calculator calc = {1, sub };
    int val = calc.apply(10, 3);
    if(val != 7) return 104;
    return 0;
}
