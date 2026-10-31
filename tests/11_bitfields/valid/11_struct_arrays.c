/*
 * TEST: struct_arrays
 * Arrays of bit-field structs (1-D and 2-D): indexing, pointer walking, pointer
 * arithmetic, element copy.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 4; signed int b : 6; unsigned c : 5; };

static struct S g[8];

int main(void)
{
    struct S loc[8];
    struct S m[3][4];
    struct S *p;
    int i, j;

    CHECK(sizeof(g) / sizeof(g[0]) == 8);
    for (i = 0; i < 8; i++) {
        g[i].a = i; g[i].b = -i * 3; g[i].c = i * 4;
        loc[i] = g[i];
    }
    for (i = 0; i < 8; i++) {
        CHECK(g[i].a == i && g[i].b == -i * 3 && g[i].c == i * 4);
        CHECK(loc[i].a == i && loc[i].b == -i * 3 && loc[i].c == i * 4);
    }
    for (p = g, i = 0; p < g + 8; p++, i++)
        CHECK(p->a == i);
    CHECK((g + 3)->b == -9);
    CHECK((*(g + 5)).c == 20);

    p = &g[2];
    p->a += 5;
    CHECK(g[1].a == 1 && g[2].a == 7 && g[3].a == 3 && g[2].c == 8);
    CHECK(p[1].a == 3 && p[-1].a == 1 && (&g[6] - p) == 4);

    loc[0] = g[7];
    CHECK(loc[0].a == 7 && loc[0].b == -21 && loc[0].c == 28 && loc[1].a == 1);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++) {
            m[i][j].a = i * 4 + j;
            m[i][j].b = i - j;
            m[i][j].c = i ^ j;
        }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            CHECK(m[i][j].a == i * 4 + j && m[i][j].b == i - j && m[i][j].c == (i ^ j));
    return 0;
}
