// Exit code: 0
/* Test: Explicit assignment and continuation. */
enum E { A = 5, B, C = 10, D };
int main() {
    if (A != 5) return 1;
    if (B != 6) return 2;
    if (C != 10) return 3;
    if (D != 11) return 4;
    return 0;
}