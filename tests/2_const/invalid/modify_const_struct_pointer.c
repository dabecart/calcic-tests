struct Point { int x; int y; };
int main() {
    const struct Point p = {1, 2};
    const struct Point *p_p = &p;
    p_p->x = 10; /* ERROR: Assignment of member 'x' in read-only object */
    return 0;
}