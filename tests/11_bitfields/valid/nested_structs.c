/* Valid: Nested structures containing bitfields */
struct Inner {
    unsigned int x : 3;
};

struct Outer {
    struct Inner in;
    unsigned int y : 5;
};

int main(void) {
    struct Outer o;
    o.in.x = 7;
    o.y = 31;
    if (o.in.x != 7 || o.y != 31) return 1;
    return 0;
}
