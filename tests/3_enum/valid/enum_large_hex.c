// Exit code: 0
/* Test: Large hex value in enum. */
enum E { L = 0xFFFF };
int main() {
    if (L != 65535) return 1;
    return 0;
}