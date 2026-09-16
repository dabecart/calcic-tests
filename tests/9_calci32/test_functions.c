
int add(int a, int b) { return a + b; }

int max(int a, int b) { return (a > b) ? a : b; }

int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int many_args(int a, int b, int c, int d, int e, int f, int g, int h) {
    return a+b+c+d+e+f+g+h;
}

int main(void) {
    if (add(5, 7) != 12) return 1;
    if (max(10, 20) != 20) return 2;
    if (fib(6) != 8) return 3; // Tests stack frame recursion
    if (many_args(1,2,3,4,5,6,7,8) != 36) return 4; // Tests calling convention (registers/stack)
    return 0;
}
