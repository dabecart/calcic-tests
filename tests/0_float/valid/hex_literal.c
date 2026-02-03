// Exit code: 0
/* Test C99 hex float literal */
int main() {
    float f = 0x1.8p1; // 1.5 * 2^1 = 3.0
    if (f != 3.0f) return 1;
    return 0;
}