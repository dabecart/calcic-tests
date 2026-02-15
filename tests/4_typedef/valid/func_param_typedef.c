// Exit code: 0
typedef int ArgType;
int foo(ArgType x) { return x + 1; }

int main(void) {
    if (foo(5) != 6) return 1;
    return 0;
}