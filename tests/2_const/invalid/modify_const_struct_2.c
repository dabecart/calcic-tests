struct Point { int x; int y; };
int main() {
    const struct Point p = {1, 2};
    p.x++; /* ERROR: Assignment of member 'x' in read-only object */
    return 0;
}