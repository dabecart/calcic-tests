// Exit code: 0
/* Test floats in recursion (stack handling) */
float factorial(float n) {
    if (n <= 1.0f) return 1.0f;
    return n * factorial(n - 1.0f);
}

int main() {
    if (factorial(5.0f) != 120.0f) return 1;
    return 0;
}