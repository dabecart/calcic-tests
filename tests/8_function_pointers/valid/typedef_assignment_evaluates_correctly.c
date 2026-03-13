// Exit code: 0
typedef int (*math_op)(int, int);
int add(int a, int b) { return a + b; }
int main(void) {
    math_op op = add;
    int val = op(10, 5);
    if(val != 15) return 101;
    return 0;
}
