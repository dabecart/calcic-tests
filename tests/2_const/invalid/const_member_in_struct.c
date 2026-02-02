struct Point {
    const float x;
    const float y;
};

int main() {
    struct Point p = {10, 5};
    p.x = 11; /* ERROR: x is a const member. */
    return 0;
}