// Exit code: 0
/* Test passing structs with floats by value */
struct Point { float x; float y; };

struct Point add(struct Point a, struct Point b) {
    struct Point res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

int main() {
    struct Point p1 = {1.5f, 2.5f};
    struct Point p2 = {0.5f, 0.5f};
    struct Point p3 = add(p1, p2);
    
    if (p3.x != 2.0f) return 1;
    if (p3.y != 3.0f) return 2;
    return 0;
}