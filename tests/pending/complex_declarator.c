// Exit code: 0
// Array of 2 pointers to functions returning int
typedef int (*FuncArr[2])(void);

int f1(void) { return 1; }
int f2(void) { return 2; }

int main(void) {
    FuncArr fa = {f1, f2};
    if (fa[0]() + fa[1]() != 3) return 1;
    return 0;
}