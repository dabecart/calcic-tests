/*
 * TEST: function_args_by_value
 * Passing bit-field structs and bit-field values by value: callee modifications
 * are invisible to the caller, promotion of bit-field arguments, mixed argument
 * lists with doubles, nested calls.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 5; signed int b : 9; unsigned c : 3; };

static int sum(struct S s) { return (int)s.a + s.b + (int)s.c; }
static struct S bump(struct S s) { s.a++; s.b = -s.b; s.c = 7; return s; }
static void clobber(struct S s) { s.a = 0; s.b = 0; s.c = 0; }
static int add_bits(int x, unsigned y, int z) { return x * 100 + (int)y * 10 + z; }
static int six(int p1, struct S s, int p2, struct S t, double d, int p3)
{
    return p1 + p2 * 10 + p3 * 100 + sum(s) + sum(t) + (int)d;
}

int main(void)
{
    struct S s = {10, -50, 3};
    struct S t;
    struct S u = {3, -2, 1};

    CHECK(sum(s) == -37);
    t = bump(s);
    CHECK(t.a == 11 && t.b == 50 && t.c == 7);
    CHECK(s.a == 10 && s.b == -50 && s.c == 3);
    clobber(s);
    CHECK(s.a == 10 && s.b == -50 && s.c == 3);
    CHECK(add_bits(u.c, u.a, u.b) == 128);
    CHECK(sum(bump(bump(s))) == -31);
    CHECK(six(1, s, 2, t, 4.0, 3) == 356);
    CHECK(sum((struct S){1, 2, 3}) == 6);
    return 0;
}
