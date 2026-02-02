int main() {
    int x = 10;
    int y = 20;
    int * const p = &x;
    p = &y; /* ERROR: Assignment to read-only variable 'p' (the pointer itself) */
    return 0;
}