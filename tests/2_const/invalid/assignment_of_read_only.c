int main() {
    int x = 10;
    const int *p = &x;
    *p = 20; /* ERROR: Assignment of read-only location '*p' */
    return 0;
}