/* Error: Arithmetic on void pointer using float literal logic */
void test() {
    void *p = 0;
    p = p * 2.0f;
}