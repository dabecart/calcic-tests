// Exit code: 0
/* Test passing multiple float arguments */
float sum3(float a, float b, float c) {
    return a + b + c;
}

int main() {
    if (sum3(1.0f, 2.0f, 3.0f) != 6.0f) return 1;
    return 0;
}