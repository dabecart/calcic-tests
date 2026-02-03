/* Error: Left shift (<<) invalid for floats */
void test() {
    float a = 1.0f;
    int b = 1 << a;
}