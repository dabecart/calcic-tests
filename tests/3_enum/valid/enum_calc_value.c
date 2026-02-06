// Exit code: 0
/* Test: Enum value defined by calculation of previous values. */
enum E { A = 1, B = A + 2, C = B * 2 };
int main() {
    if (A != 1) return 1;
    if (B != 3) return 2;
    if (C != 6) return 3;
    return 0;
}