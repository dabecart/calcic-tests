int main() {
    const int x = 10;
    /* You cannot implicitly convert const T* to void* (must be const void*) */
    void *p = &x; /* ERROR: Initialization discards 'const' qualifier */
    return 0;
}