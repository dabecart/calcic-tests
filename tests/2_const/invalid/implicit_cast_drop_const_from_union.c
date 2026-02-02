struct IntPoint { int x; int y; };
struct FloatPoint { float x; float y; };
union Point {
    struct IntPoint i; 
    struct FloatPoint f;
};

int main() {
    const struct IntPoint ip = {1, 2};
    const union Point up = {ip};
    union Point *p_p = &up; /* ERROR: Should be const union Point *p_p */
    return 0;
}