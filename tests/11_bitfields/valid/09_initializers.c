/*
 * TEST: initializers
 * Static and automatic initialisation: positional, designated, partial, nested,
 * arrays, unnamed members being skipped, run-time initialiser expressions.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 3; signed int b : 5; unsigned : 4; unsigned c : 10; };
struct P { struct S s; unsigned x : 4; };

static struct S g1 = {1, -2, 3};
static struct S g2 = {.c = 1000, .a = 7};
static struct S g3 = {.b = -16};
static struct S g4;
static struct S garr[3] = { {1, 1, 1}, {.a = 2, .b = -2, .c = 2}, {7, -1, 1023} };
static struct S gsp[4] = { [2] = {.a = 3}, [1] = {.c = 9} };
static struct P gp  = { {5, -5, 500}, 9 };
static struct P gp2 = { .s = {.c = 11}, .x = 15 };

int main(void)
{
    int v = 4;
    struct S l1 = {1};
    struct S l2 = {v, -v, v * 100};
    struct S l3 = {.c = 77};
    struct S l4 = g1;
    struct S larr[2] = { {3, 3, 3}, {.b = 5} };
    struct P lp = { .x = 2, .s = {.a = 6} };

    CHECK(g1.a == 1 && g1.b == -2 && g1.c == 3);
    CHECK(g2.a == 7 && g2.b == 0 && g2.c == 1000);
    CHECK(g3.a == 0 && g3.b == -16 && g3.c == 0);
    CHECK(g4.a == 0 && g4.b == 0 && g4.c == 0);
    CHECK(garr[0].a == 1 && garr[0].b == 1 && garr[0].c == 1);
    CHECK(garr[1].a == 2 && garr[1].b == -2 && garr[1].c == 2);
    CHECK(garr[2].a == 7 && garr[2].b == -1 && garr[2].c == 1023);
    CHECK(gsp[0].a == 0 && gsp[0].c == 0);
    CHECK(gsp[1].a == 0 && gsp[1].c == 9);
    CHECK(gsp[2].a == 3 && gsp[2].c == 0);
    CHECK(gsp[3].a == 0 && gsp[3].b == 0 && gsp[3].c == 0);
    CHECK(gp.s.a == 5 && gp.s.b == -5 && gp.s.c == 500 && gp.x == 9);
    CHECK(gp2.s.a == 0 && gp2.s.b == 0 && gp2.s.c == 11 && gp2.x == 15);

    CHECK(l1.a == 1 && l1.b == 0 && l1.c == 0);
    CHECK(l2.a == 4 && l2.b == -4 && l2.c == 400);
    CHECK(l3.a == 0 && l3.b == 0 && l3.c == 77);
    CHECK(l4.a == 1 && l4.b == -2 && l4.c == 3);
    CHECK(larr[0].a == 3 && larr[0].b == 3 && larr[0].c == 3);
    CHECK(larr[1].a == 0 && larr[1].b == 5 && larr[1].c == 0);
    CHECK(lp.s.a == 6 && lp.s.b == 0 && lp.s.c == 0 && lp.x == 2);
    return 0;
}
