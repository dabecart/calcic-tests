/*
 * TEST: register_and_inline
 * `register` structs with bit-fields and C99 `static inline` functions taking and
 * returning bit-field structs.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 6; signed int b : 6; };

static inline struct S mk(int a, int b)
{
    struct S s;
    s.a = a; s.b = b;
    return s;
}
static inline int sum(struct S s) { return (int)s.a + s.b; }

int main(void)
{
    register struct S r = {1, -1};
    register struct S acc = {0, 0};
    register unsigned ru;
    register int i;

    r.a += 5; r.b--;
    CHECK(r.a == 6 && r.b == -2);
    ru = r.a;
    CHECK(ru == 6);

    for (i = 0; i < 20; i++) { acc.a += i & 3; acc.b ^= 1; }
    CHECK(acc.a == 30 && acc.b == 0);
    CHECK(sum(mk(3, -9)) == -6);
    CHECK(sum(mk(r.a, r.b)) == 4);
    return 0;
}
