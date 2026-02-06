// Exit code: 0
/* Test: Multiple identifiers sharing the same value. */
enum E { A = 10, B = 10, C };
int main() {
    if (A != 10) return 1;
    if (B != 10) return 2;
    if (C != 11) return 3;
    if (A != B) return 4; // Expected equality
    return 0;
}