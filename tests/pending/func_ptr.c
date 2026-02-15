// Exit code: 0
typedef int (*Op)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main(void) {
    Op f = add;
    if (f(10, 5) != 15) return 1;
    f = sub;
    if (f(10, 5) != 5) return 2;
    return 0;
}