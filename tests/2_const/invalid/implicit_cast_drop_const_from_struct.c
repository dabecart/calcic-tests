struct Point { int x; int y; };
int main() {
    const struct Point p = {1, 2};
    struct Point *p_p = &p; /* ERROR: Should be const struct Point *p_p */
    return 0;
}