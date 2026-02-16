// Exit code: 0
// Passing tagless types to functions by value and reference.
typedef struct { int a; int b; } Point;

int sum_vals(Point p) {
    return p.a + p.b;
}

void modify_pt(Point *p) {
    p->a = 100;
}

int main(void) {
    Point pt = { 10, 20 };
    
    /* Pass by value */
    if (sum_vals(pt) != 30) return 1;

    /* Pass by reference */
    modify_pt(&pt);
    if (pt.a != 100) return 2;

    return 0;
}
