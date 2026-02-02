int main() {
    const int x = 10;
    int *p = &x; /* ERROR: Initialization discards 'const' qualifier from pointer target type */
    return 0;
}