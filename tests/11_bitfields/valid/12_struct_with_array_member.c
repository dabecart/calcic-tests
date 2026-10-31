/*
 * TEST: struct_with_array_member
 * Structs mixing bit-fields and array members; bit-fields used as indices, loop
 * counters and negative offsets; arrays of such structs with nested initialisers.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S {
    unsigned n : 4;
    int v[4];
    signed int k : 6;
    unsigned char raw[3];
    unsigned flags : 8;
};

static struct S g;

int main(void)
{
    struct S s = {0};
    int i;
    int *q;

    for (i = 0; i < 4; i++) s.v[i] = 10 * i;
    for (i = 0; i < 3; i++) s.raw[i] = (unsigned char)(200 + i);
    s.n = 9; s.k = -17; s.flags = 0xA5;
    CHECK(s.n == 9 && s.k == -17 && s.flags == 0xA5);
    for (i = 0; i < 4; i++) CHECK(s.v[i] == 10 * i);
    for (i = 0; i < 3; i++) CHECK(s.raw[i] == 200 + i);

    s.n = 3; s.v[s.n] = 99;
    CHECK(s.v[3] == 99 && s.v[2] == 20);
    q = s.v + 2; s.k = -2;
    CHECK(q[s.k] == 0);

    for (s.n = 0; s.n < 4; s.n++) s.v[s.n] = (int)(s.n * s.n);
    CHECK(s.n == 4 && s.v[0] == 0 && s.v[1] == 1 && s.v[2] == 4 && s.v[3] == 9);
    CHECK(s.k == -2 && s.flags == 0xA5 && s.raw[0] == 200 && s.raw[2] == 202);

    CHECK(g.n == 0 && g.k == 0 && g.flags == 0 && g.v[3] == 0 && g.raw[2] == 0);

    {
        struct S arr[2] = {
            {1,  {1, 2, 3, 4}, -1, {'a', 'b', 'c'}, 255},
            {15, {5, 6, 7, 8}, 31, {'x', 'y', 'z'}, 1}
        };
        CHECK(arr[0].n == 1 && arr[0].v[3] == 4 && arr[0].k == -1);
        CHECK(arr[0].raw[2] == 'c' && arr[0].flags == 255);
        CHECK(arr[1].n == 15 && arr[1].v[0] == 5 && arr[1].k == 31);
        CHECK(arr[1].raw[1] == 'y' && arr[1].flags == 1);
    }
    return 0;
}
