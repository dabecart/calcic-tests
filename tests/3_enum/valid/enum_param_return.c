// Exit code: 0
/* Test: Function taking and returning enums. */
enum State { S1, S2 };
enum State next(enum State s) {
    if (s == S1) return S2;
    return S1;
}
int main() {
    if (next(S1) != S2) return 1;
    if (next(S2) != S1) return 2;
    return 0;
}