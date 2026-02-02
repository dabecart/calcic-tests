int main() {
    const int x = 10;
    x++; /* ERROR: Increment of read-only variable 'x' */
    return 0;
}