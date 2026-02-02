int main() {
    const int x = 10;
    x = 20; /* ERROR: Assignment to read-only variable 'x' */
    return 0;
}