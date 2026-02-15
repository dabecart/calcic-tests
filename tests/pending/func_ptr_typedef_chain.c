// Exit code: 0
typedef int FuncType(void);
typedef FuncType *FuncPtr;

int foo(void) { return 99; }

int main(void) {
    FuncPtr p = foo;
    if (p() != 99) return 1;
    return 0;
}