// Exit code: 0
/* Test: Negative values in enums. */
enum E { A = -1, B, C = -5 };
int main() {
    if (A != -1) return 1;
    if (B != 0) return 2;
    if (C != -5) return 3;
    return 0;
}