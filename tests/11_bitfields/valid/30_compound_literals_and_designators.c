/*
 * TEST: compound_literals_and_designators
 * C99 compound literals and designated initialisers with bit-fields: as arguments,
 * as rvalues, address of the literal itself (legal), arrays of literals.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 5; signed int b : 7; unsigned c : 3; };
struct P { struct S s; unsigned x : 4; };

static int sum(struct S s) { return (int)s.a + s.b + (int)s.c; }
static int sum_ptr(const struct S *p) { return (int)p->a + p->b + (int)p->c; }

int main(void)
{
    struct S s = {1, 1, 1};
    struct S *p, *arr;
    int i;

    CHECK(sum((struct S){1, 2, 3}) == 6);
    CHECK(sum((struct S){.c = 4, .a = 1}) == 5);
    CHECK(((struct S){7, -8, 1}).b == -8);

    p = &(struct S){.a = 9, .b = -9, .c = 5};
    p->a++;
    CHECK(p->a == 10 && p->b == -9 && p->c == 5);
    CHECK(sum_ptr(&(struct S){2, 2, 2}) == 6);

    CHECK((struct S[]){{1, 1, 1}, {2, -2, 2}, {3, 3, 3}}[1].b == -2);
    arr = (struct S[3]){{1}, {2}, {3}};
    for (i = 0; i < 3; i++) CHECK(arr[i].a == i + 1 && arr[i].b == 0);

    s = (struct S){.a = 3};
    CHECK(s.a == 3 && s.b == 0 && s.c == 0);
    CHECK(((struct P){.s = {.b = -1}, .x = 3}).s.b == -1);
    CHECK(((struct P){.s = {.b = -1}, .x = 3}).x == 3);
    return 0;
}
