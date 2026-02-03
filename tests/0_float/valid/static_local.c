// Exit code: 0
/* Test static local variable state retention */
float counter() {
    static float c = 0.0f;
    c += 1.0f;
    return c;
}

int main() {
    if (counter() != 1.0f) return 1;
    if (counter() != 2.0f) return 2;
    return 0;
}