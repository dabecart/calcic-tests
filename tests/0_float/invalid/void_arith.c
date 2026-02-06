/* Error: Arithmetic on void pointer using float literal logic */
int main() {
    void *p = 0;
    p = p * 2.0f;
    return 0;
}