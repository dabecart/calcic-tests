// Exit code: 0
int main(void) {
    typedef struct { int a; } S;
    S obj = {10};
    if (obj.a != 10) return 1;
    return 0;
}