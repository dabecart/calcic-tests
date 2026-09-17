#include <stdint.h>

struct Point {
    int32_t x;
    int32_t y;
};

struct Nested {
    struct Point p;
    int32_t z;
};

union Data {
    uint32_t i;
    uint8_t c[4];
};

int main(void) {
    struct Point p1 = {10, 20};
    if (p1.x != 10 || p1.y != 20) return 1;

    struct Point *ptr = &p1;
    ptr->x = 50;
    if (p1.x != 50) return 2;

    struct Nested n = {{1, 2}, 3};
    if (n.p.x != 1 || n.z != 3) return 3;

    union Data d;
    d.i = 0x11223344;
    // Test ignores endianness by just checking if memory is shared
    if (d.c[0] != 0x44 && d.c[0] != 0x11) return 4;

    d.c[0] = 0x00;
    if (d.i == 0x11223344) return 5;

    return 0;
}
