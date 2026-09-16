int main(void) {
    int a = 15, b = 4;
    if (a + b != 19) return 1;
    if (a - b != 11) return 2;
    if (a * b != 60) return 3;
    if (a / b != 3) return 4;
    if (a % b != 3) return 5;

    char c = 120, d = 10;
    if ((char)(c + d) != -126) return 6; // Overflow test

    short e = -30000, f = -10000;
    if (e - f != -20000) return 7;

    unsigned int u1 = 0xFFFFFFFF, u2 = 1;
    if (u1 + u2 != 0) return 8; // Unsigned wrap

    return 0;
}
