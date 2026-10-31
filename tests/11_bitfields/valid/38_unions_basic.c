/*
 * TEST: unions_basic
 * Unions whose members are bit-field structs: only the active member is read, so
 * no layout assumption is made.  Arrays of unions, union by value.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

union U {
    struct { unsigned a : 4; } x;
    struct { signed int b : 9; unsigned c : 3; } y;
    int whole;
};

static int get(union U u, int which) { return which ? u.y.b : (int)u.x.a; }

int main(void)
{
    union U u;
    union U arr[3];
    int i;

    u.x.a = 5;
    CHECK(u.x.a == 5);
    u.y.b = -100; u.y.c = 6;
    CHECK(u.y.b == -100 && u.y.c == 6);
    u.whole = 0;
    u.x.a = 12;
    CHECK(get(u, 0) == 12);
    u.y.b = -7;
    CHECK(get(u, 1) == -7);

    for (i = 0; i < 3; i++) { arr[i].y.b = i * 50 - 60; arr[i].y.c = i; }
    for (i = 0; i < 3; i++) CHECK(arr[i].y.b == i * 50 - 60 && arr[i].y.c == i);
    return 0;
}
