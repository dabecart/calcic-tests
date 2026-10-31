/*
 * TEST: function_returns
 * Functions returning bit-field structs (small and large), bit-field values,
 * _Bool bit-fields; member access on call results; conditional struct results.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S   { unsigned a : 5; signed int b : 9; unsigned c : 3; };
struct Big { unsigned a : 3; unsigned b : 30; int arr[4]; signed int c : 17; double d; };

static struct S make(unsigned a, int b, unsigned c)
{
    struct S s;
    s.a = a; s.b = b; s.c = c;
    return s;
}
static struct S pick(int cond, struct S x, struct S y) { return cond ? x : y; }
static int get_b(const struct S *p) { return p->b; }
static unsigned get_a(struct S s) { return s.a; }
static _Bool is_big(struct S s) { return s.a > 15; }
static struct S chain(struct S s) { return make(s.a + 1, s.b * 2, s.c); }
static struct Big make_big(int k)
{
    struct Big B;
    int i;
    B.a = k; B.b = k * 1000;
    for (i = 0; i < 4; i++) B.arr[i] = k + i;
    B.c = -k * 100; B.d = k + 0.5;
    return B;
}

int main(void)
{
    struct S t, arr[3];
    struct Big B;

    CHECK(make(3, -4, 5).a == 3 && make(3, -4, 5).b == -4 && make(3, -4, 5).c == 5);
    CHECK(make(1, 2, 3).a + make(4, 5, 6).b == 6);
    t = make(31, -256, 7);
    CHECK(t.a == 31 && t.b == -256 && t.c == 7);

    t = pick(1, make(1, 1, 1), make(2, 2, 2));
    CHECK(t.a == 1 && t.b == 1);
    t = pick(0, make(1, 1, 1), make(2, 2, 2));
    CHECK(t.a == 2 && t.b == 2);
    CHECK(get_b(&t) == 2);
    CHECK(get_a(make(9, 0, 0)) == 9);
    CHECK(is_big(make(16, 0, 0)) && !is_big(make(15, 0, 0)));

    t = chain(chain(make(1, -3, 2)));
    CHECK(t.a == 3 && t.b == -12 && t.c == 2);

    arr[0] = make(1, 1, 1); arr[1] = chain(arr[0]); arr[2] = chain(arr[1]);
    CHECK(arr[2].a == 3 && arr[2].b == 4 && arr[1].a == 2 && arr[0].a == 1);

    B = make_big(5);
    CHECK(B.a == 5 && B.b == 5000 && B.arr[0] == 5 && B.arr[3] == 8);
    CHECK(B.c == -500 && B.d == 5.5);
    CHECK(make_big(2).b == 2000 && make_big(7).arr[2] == 9 && make_big(3).c == -300);
    return 0;
}
