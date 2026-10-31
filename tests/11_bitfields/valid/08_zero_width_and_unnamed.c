/*
 * TEST: zero_width_and_unnamed
 * Unnamed bit-fields (padding) and zero-width fields: they are skipped by
 * initialisers, never disturb named fields, and zero width forces a new unit.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct Z1 { unsigned a : 3; unsigned : 0; unsigned b : 3; };
struct Z2 { unsigned a : 3; unsigned : 5; unsigned b : 3; };
struct Z3 { signed int x : 4; signed int : 0; signed int y : 4; signed int : 3; signed int z : 4; };

int main(void)
{
    struct Z1 y1 = {7, 7};
    struct Z2 y2 = {1, 2};
    struct Z3 y3 = {-1, -2, -3};
    struct Z1 arr[3];
    struct Z1 c1;
    int i;

    CHECK(y1.a == 7 && y1.b == 7);
    CHECK(y2.a == 1 && y2.b == 2);
    CHECK(y3.x == -1 && y3.y == -2 && y3.z == -3);

    y1.a = 0; CHECK(y1.a == 0 && y1.b == 7);
    y1.b = 0; y1.a = 5; CHECK(y1.a == 5 && y1.b == 0);
    y2.a = 7; y2.b = 0; CHECK(y2.a == 7 && y2.b == 0);
    y2.b = 7; y2.a = 0; CHECK(y2.a == 0 && y2.b == 7);
    y3.y = 7; CHECK(y3.x == -1 && y3.y == 7 && y3.z == -3);
    y3.x = 3; y3.z = -8; CHECK(y3.x == 3 && y3.y == 7 && y3.z == -8);

    CHECK(sizeof(struct Z1) == 2 * sizeof(unsigned));
    CHECK(sizeof(struct Z1) > sizeof(struct Z2));

    for (i = 0; i < 3; i++) { arr[i].a = i + 1; arr[i].b = 6 - i; }
    for (i = 0; i < 3; i++) CHECK(arr[i].a == i + 1 && arr[i].b == 6 - i);

    c1 = arr[1];
    CHECK(c1.a == 2 && c1.b == 5);
    c1.a = 0;
    CHECK(arr[1].a == 2);
    return 0;
}
