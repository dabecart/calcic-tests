/*
 * TEST: const_and_volatile
 * const and volatile qualified structs with bit-fields; const member bit-field;
 * copying out of const/volatile objects.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 4; signed int b : 5; unsigned c : 7; };
struct CM { const unsigned a : 3; unsigned b : 3; };

static int read_const(const struct S *p) { return p->a + p->b + p->c; }

int main(void)
{
    const struct S cs = {9, -3, 100};
    const struct S carr[2] = {{1, 2, 3}, {4, -5, 6}};
    volatile struct S vs = {1, 1, 1};
    volatile struct S *vp = &vs;
    struct S s2, t;
    struct CM cm = {5, 2};

    CHECK(cs.a == 9 && cs.b == -3 && cs.c == 100);
    CHECK(read_const(&cs) == 106);
    CHECK(carr[1].b == -5 && carr[0].c == 3);
    t = cs;
    t.a = 1;
    CHECK(cs.a == 9 && t.a == 1 && t.b == -3);

    vs.a = 5; vs.a++; vs.b -= 3;
    CHECK(vs.a == 6 && vs.b == -2 && vs.c == 1);
    vp->c = 127; vp->c++;
    CHECK(vs.c == 0 && vs.a == 6);
    s2 = vs;
    CHECK(s2.a == 6 && s2.b == -2 && s2.c == 0);

    cm.b = 3;
    CHECK(cm.a == 5 && cm.b == 3);
    return 0;
}
