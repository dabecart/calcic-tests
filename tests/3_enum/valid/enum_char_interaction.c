// Exit code: 0
/* Test: Enum interaction with char (promotion). */
enum E { C = 'A' };
int main() {
    if (C != 65) return 1;
    char c = C;
    if (c != 'A') return 2;
    return 0;
}