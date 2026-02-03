/* Error: Assignment of read-only variable */
void test() {
    const float f = 1.0f;
    f = 2.0f;
}