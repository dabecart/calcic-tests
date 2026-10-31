/*
 * TEST: function_pointers
 * Function pointers taking/returning bit-field structs: arrays of pointers,
 * callbacks, tables of structs holding both bit-fields and function pointers.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 4; signed int b : 6; unsigned c : 5; };
typedef struct S (*fn)(struct S);

static struct S f_inc(struct S s) { s.a++; return s; }
static struct S f_neg(struct S s) { s.b = -s.b; return s; }
static struct S f_sum(struct S s) { s.c = s.a + s.b; return s; }

static struct S apply(fn f, struct S s) { return f(s); }
static struct S apply_all(fn *fs, int n, struct S s)
{
    int i;
    for (i = 0; i < n; i++) s = fs[i](s);
    return s;
}

struct Op { unsigned id : 3; fn f; unsigned prio : 5; };
static const struct Op ops[] = { {1, f_inc, 10}, {2, f_neg, 20}, {3, f_sum, 30} };

int main(void)
{
    struct S s = {3, 5, 0};
    struct S r;
    fn fs[4];
    const struct Op *po;
    int i;

    r = apply(f_inc, s);
    CHECK(r.a == 4 && r.b == 5 && s.a == 3);

    fs[0] = f_inc; fs[1] = f_neg; fs[2] = f_inc; fs[3] = f_sum;
    r = apply_all(fs, 4, s);
    CHECK(r.a == 5 && r.b == -5 && r.c == 0);

    CHECK(ops[2].id == 3 && ops[2].prio == 30);
    CHECK(ops[1].f(s).b == -5);
    r = s;
    for (i = 0; i < 3; i++) r = ops[i].f(r);
    CHECK(r.a == 4 && r.b == -5 && r.c == 31);
    po = &ops[0];
    CHECK(po->f(s).a == 4 && po->prio == 10);
    return 0;
}
