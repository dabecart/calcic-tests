/*
 * TEST: globals_and_extern
 * File-scope bit-field structs: extern declaration before definition, tentative
 * definitions, constant pointers to globals, pointers into global arrays.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 4; signed int b : 6; unsigned c : 10; };

extern struct S g;
extern struct S garr[3];
struct S tent;
struct S tent;                       /* tentative definition, twice */

static int read_g(void) { return g.a + g.b + g.c; }

struct S g = {3, -4, 500};
struct S garr[3] = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };

static struct S *const gp = &g;
static struct S *garr_p = garr + 1;

int main(void)
{
    CHECK(read_g() == 499);
    gp->a = 15; g.b = -32;
    CHECK(read_g() == 15 - 32 + 500);
    garr_p[1].c++;
    CHECK(garr[2].c == 4 && garr[1].c == 2 && garr[0].c == 1);
    garr_p->b = -7;
    CHECK(garr[1].b == -7 && garr[0].b == 1);
    CHECK(tent.a == 0 && tent.b == 0 && tent.c == 0);
    tent.c = 1023;
    CHECK(tent.c == 1023 && tent.a == 0);
    return 0;
}
