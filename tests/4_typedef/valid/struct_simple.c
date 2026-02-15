// Exit code: 0
struct P {
    int x;
    int y;
};
typedef struct P Point;

int main(void) {
    Point p = {10, 20};
    if (p.x != 10) return 1;
    if (p.y != 20) return 2;
    return 0;
}