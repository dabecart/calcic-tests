// Exit code: 0
/* Test ternary operator with floats */
int main() {
    float a = 10.0f;
    float b = 20.0f;
    float res = (a > b) ? a : b;
    if (res != 20.0f) return 1;
    return 0;
}