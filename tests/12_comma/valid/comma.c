/*
 * comma.c - Thorough test of the C99 comma operator.
 *
 * Exit status:
 *   0      -> every check passed
 *   N != 0 -> a check inside test number N failed (see the tNN_ functions;
 *             the number is also stored in the enum constant T of each one).
 *
 * NOTE: a conforming compiler may warn about "left operand of comma has no
 * effect"; that is expected, many tests do this on purpose.
 */

/* ------------------------------------------------------------------ */
/* Helpers                                                            */
/* ------------------------------------------------------------------ */

#define CHECK(...) do { if (!(__VA_ARGS__)) return T; } while (0)

static int g_count;   /* general purpose counter            */
static int g_trace;   /* decimal digits trace of evaluation */
static int g_val;     /* last value stored by set_val       */
static int g_calls;   /* recursion call counter             */

static int next(void)          { return ++g_count; }
static int tr(int d)           { g_trace = g_trace * 10 + d; return d; }
static void set_val(int v)     { g_val = v; }
static int add(int a, int b)   { return a + b; }
static int sub(int a, int b)   { return a - b; }
static int add3(int a, int b, int c) { return a + b + c; }
static int twice(int x)        { return x * 2; }
static int neg(int x)          { return -x; }
static int apply(int (*f)(int), int v) { return f(v); }

static int counter(void)
{
    static int n;
    return (n++, n);
}

struct pt { int x, y; };

static struct pt make_pt(int x, int y)
{
    struct pt p;
    p.x = x;
    p.y = y;
    return p;
}

static int pt_sum(struct pt p) { return p.x + p.y; }

/* return statements using the comma operator */
static int ret_comma(int x)   { return g_val = x, g_val += 1, g_val * 2; }
static int ret_unparen(int x) { return x += 1, x *= 2, x; }
static int ret_paren(int x)   { return (x = x + 1, x * 10); }
static struct pt ret_struct_comma(int a)
{
    struct pt p = { 1, 2 };
    return g_val = a, p;
}
static int *ret_ptr_comma(int *p) { return g_val = 77, p; }

static int fact(int n)
{
    return (g_calls++, n <= 1) ? 1 : n * fact(n - 1);
}

static int fib(int n)
{
    return n < 2 ? (g_calls++, n) : fib(n - 1) + fib(n - 2);
}

/* macros */
#define PASS(x)       x
#define FIRST(a, b)   (a)
#define SWAP(t, x, y) ((t) = (x), (x) = (y), (y) = (t))
#define MAXV(a, b)    ((a) > (b) ? (a) : (b))

/* ------------------------------------------------------------------ */
/* Tests                                                              */
/* ------------------------------------------------------------------ */

/* 1: value of a comma expression is the value of the right operand */
static int t01_basic_value(void)
{
    enum { T = 1 };
    int a = (1, 2, 3);
    CHECK(a == 3);
    int b = (1, 2, 3) + 10;
    CHECK(b == 13);
    CHECK((5, 6) == 6);
    CHECK(((7, 8), (9, 10)) == 10);
    return 0;
}

/* 2: left operand side effects are performed before the right is used */
static int t02_side_effects(void)
{
    enum { T = 2 };
    int i = 0, x;
    x = (i = 5, i + 1);
    CHECK(x == 6);
    CHECK(i == 5);

    int a = 1, b = 2;
    x = (a = b, b = a + 10, a + b);
    CHECK(a == 2);
    CHECK(b == 12);
    CHECK(x == 14);
    return 0;
}

/* 3: strict left-to-right order (sequence point) */
static int t03_evaluation_order(void)
{
    enum { T = 3 };
    int r;
    g_trace = 0;
    r = (tr(1), tr(2), tr(3));
    CHECK(r == 3);
    CHECK(g_trace == 123);

    g_trace = 0;
    r = ((tr(1), tr(2)), (tr(3), tr(4)));
    CHECK(r == 4);
    CHECK(g_trace == 1234);

    g_trace = 0;
    r = ((tr(1), (tr(2), tr(3))), tr(4));
    CHECK(r == 4);
    CHECK(g_trace == 1234);
    return 0;
}

/* 4: left operand value is discarded */
static int t04_discarded_left(void)
{
    enum { T = 4 };
    int a = 0, b = 0, r;
    r = (a++, b += 2, a + b);
    CHECK(a == 1);
    CHECK(b == 2);
    CHECK(r == 3);

    r = (a++, b++);
    CHECK(r == 2);   /* post-increment yields old value of b */
    CHECK(a == 2);
    CHECK(b == 3);
    return 0;
}

/* 5: comma has the lowest precedence, below assignment */
static int t05_precedence_assignment(void)
{
    enum { T = 5 };
    int x, y, z, w;
    x = 1, 2;
    CHECK(x == 1);

    y = (1, 2);
    CHECK(y == 2);

    z = w = (3, 4);
    CHECK(z == 4);
    CHECK(w == 4);

    x = 5, y = 6, z = 7;
    CHECK(x == 5);
    CHECK(y == 6);
    CHECK(z == 7);
    return 0;
}

/* 6: interaction with the conditional operator */
static int t06_ternary(void)
{
    enum { T = 6 };
    int a = 0, b = 0, r;

    r = 1 ? (a = 1, 10) : (b = 1, 20);
    CHECK(r == 10);
    CHECK(a == 1);
    CHECK(b == 0);

    r = 0 ? (a = 2, 10) : (b = 2, 20);
    CHECK(r == 20);
    CHECK(a == 1);
    CHECK(b == 2);

    /* the middle operand of ?: is a full "expression": commas allowed */
    r = 1 ? a = 3, 30 : 40;
    CHECK(r == 30);
    CHECK(a == 3);

    r = (a = 0, a ? 1 : 2);
    CHECK(r == 2);

    r = 0 ? 1 : (2, 3);
    CHECK(r == 3);

    r = (1 ? (2, 3) : (4, 5));
    CHECK(r == 3);
    return 0;
}

/* 7: comma in for loops */
static int t07_for_loops(void)
{
    enum { T = 7 };
    int i, j, n = 0, s;

    for (i = 0, j = 10; i < j; i++, j--)
        n++;
    CHECK(i == 5);
    CHECK(j == 5);
    CHECK(n == 5);

    /* C99 declarations whose initializers use comma */
    s = 0;
    for (int k = (0, 2), m = 1; k < 5; k++, m *= 2)
        s += m;
    CHECK(s == 7);   /* m = 1 + 2 + 4 */

    /* comma in the controlling expression */
    n = 0;
    for (i = 0; i++, i < 5; )
        n++;
    CHECK(n == 4);
    CHECK(i == 5);

    /* 'continue' must still run the comma-expression increment */
    s = 0;
    for (i = 0, j = 0; i < 10; i++, j += 2) {
        if (i % 2)
            continue;
        s += j;
    }
    CHECK(s == 40);
    CHECK(i == 10);
    CHECK(j == 20);

    /* 'break' */
    for (i = 0, j = 100; ; i++, j--) {
        if (i == j - 90)
            break;
    }
    CHECK(i == 5);
    CHECK(j == 95);

    /* nested loops with empty body */
    for (i = 0, s = 0; i < 4; i++)
        for (j = 0; j <= i; j++, s++)
            ;
    CHECK(s == 10);
    return 0;
}

/* 8: comma in while / do-while conditions */
static int t08_while_dowhile(void)
{
    enum { T = 8 };
    int i = 0, n = 0, c;

    while (i++, i < 5)
        n++;
    CHECK(n == 4);
    CHECK(i == 5);

    i = 0;
    n = 0;
    do {
        n++;
    } while (i += 2, i < 7);
    CHECK(n == 4);
    CHECK(i == 8);

    g_count = 0;
    while (c = next(), c < 5)
        ;
    CHECK(c == 5);
    CHECK(g_count == 5);
    return 0;
}

/* 9: comma in if conditions */
static int t09_if(void)
{
    enum { T = 9 };
    int a = 0, b = 0, r;

    r = 0;
    if (a = 1, 0)
        r = 1;
    CHECK(r == 0);
    CHECK(a == 1);

    r = 0;
    if (a = 0, 5)
        r = 2;
    CHECK(r == 2);
    CHECK(a == 0);

    if (0, 0)
        r = 3;
    else
        r = 4;
    CHECK(r == 4);

    if (b = 1, b == 1)
        r = 5;
    else
        r = 6;
    CHECK(r == 5);
    return 0;
}

/* 10: comma in switch controlling expression */
static int t10_switch(void)
{
    enum { T = 10 };
    int x, r = 0;

    switch (x = 2, x + 1) {
    case 3:  r = 30; break;
    case 2:  r = 20; break;
    default: r = -1; break;
    }
    CHECK(r == 30);
    CHECK(x == 2);

    switch ((1, 2, 3)) {
    case 1:  r = 1; break;
    case 3:  r = 33; break;
    default: r = -1; break;
    }
    CHECK(r == 33);
    return 0;
}

/* 11: comma in return statements */
static int t11_return(void)
{
    enum { T = 11 };
    struct pt p;
    int v = 5;
    int *q;

    g_val = 0;
    CHECK(ret_comma(3) == 8);       /* 3 -> 4 -> 8 */
    CHECK(g_val == 4);
    CHECK(ret_unparen(3) == 8);     /* 3 -> 4 -> 8 */
    CHECK(ret_paren(4) == 50);

    p = ret_struct_comma(9);
    CHECK(g_val == 9);
    CHECK(p.x == 1);
    CHECK(p.y == 2);

    q = ret_ptr_comma(&v);
    CHECK(g_val == 77);
    CHECK(q == &v);
    CHECK(*q == 5);
    return 0;
}

/* 12: parenthesised comma vs argument separator in calls */
static int t12_call_arguments(void)
{
    enum { T = 12 };
    CHECK(add((1, 2), (3, 4)) == 6);       /* 2 + 4  */
    CHECK(sub((1, 10), (2, 3)) == 7);      /* 10 - 3 */
    CHECK(add3(1, 2, 3) == 6);             /* 3 args */
    CHECK(add3((1, 2), (3, 4), (5, 6)) == 12);
    CHECK(add3(1, (2, 3), 4) == 8);

    g_val = 0;
    CHECK(twice((g_val = 5, g_val)) == 10);
    CHECK(g_val == 5);

    CHECK(add(twice((1, 2)), (twice(3), 4)) == 8);
    return 0;
}

/* 13: function calls as operands of the comma operator */
static int t13_call_operands(void)
{
    enum { T = 13 };
    int r;

    g_count = 0;
    r = (next(), next(), next());
    CHECK(r == 3);
    CHECK(g_count == 3);

    g_val = 0;
    (set_val(1), set_val(2), set_val(3));
    CHECK(g_val == 3);

    r = (set_val(9), 7);
    CHECK(r == 7);
    CHECK(g_val == 9);

    r = (counter(), counter(), counter());
    CHECK(r == 3);
    return 0;
}

/* 14: function pointers and comma */
static int t14_function_pointers(void)
{
    enum { T = 14 };
    int (*fp)(int) = twice;
    int (*fps[2])(int) = { twice, neg };

    g_val = 0;
    CHECK((g_val = 1, fp)(21) == 42);
    CHECK(g_val == 1);
    CHECK((0, twice)(5) == 10);
    CHECK((fp, add)(1, 2) == 3);
    CHECK((tr(1), neg)(6) == -6);

    CHECK(fps[(0, 1)](4) == -4);
    CHECK(fps[(1, 0)](4) == 8);

    CHECK(apply((0, twice), (0, 4)) == 8);
    CHECK(apply((0, neg), (0, 4)) == -4);
    CHECK(apply((fp, neg), (fp, 1)) == -1);
    return 0;
}

/* 15: comma inside array subscripts */
static int t15_array_subscript(void)
{
    enum { T = 15 };
    int a[4] = { 10, 20, 30, 40 };
    int i = 0;

    CHECK(a[(0, 1)] == 20);
    CHECK(a[(i = 2, i + 1)] == 40);
    CHECK(i == 2);
    CHECK((i = 1, i)[a] == 20);

    a[(0, 1)] = 99;
    CHECK(a[1] == 99);

    a[(i = 1, i)] += 5;
    CHECK(a[1] == 104);

    CHECK(a[(i = 0, i++, i)] == 20 + 84);   /* index 1 -> 104 */
    CHECK(i == 1);
    return 0;
}

/* 16: array initializers and 2D arrays */
static int t16_array_init(void)
{
    enum { T = 16 };
    int a[3] = { (1, 2), (3, 4), (5, 6) };
    CHECK(a[0] == 2);
    CHECK(a[1] == 4);
    CHECK(a[2] == 6);

    int b[] = { 1, 2, 3 };
    CHECK(sizeof(b) == 3 * sizeof(int));

    int c[2] = { (0, 7), 8 };
    CHECK(c[0] == 7);
    CHECK(c[1] == 8);

    int v;
    int e[2] = { (v = 5, v), 7 };
    CHECK(e[0] == 5);
    CHECK(e[1] == 7);

    int m[2][3] = { { (0, 1), 2, 3 }, { 4, 5, (0, 6) } };
    CHECK(m[1][2] == 6);
    CHECK(m[(0, 1)][(1, 2)] == 6);
    CHECK(m[(1, 0)][(0, 0)] == 1);

    int (*pa)[3] = m;
    CHECK((*(0, pa))[1] == 2);
    CHECK((*(0, pa + 1))[0] == 4);
    return 0;
}

/* 17: type of the comma expression, sizeof, no evaluation under sizeof */
static int t17_types_sizeof(void)
{
    enum { T = 17 };
    char c = 1;
    short s = 2;
    long l = 3;
    int arr[3];
    int z = 0;

    CHECK(sizeof((0, c)) == sizeof(char));
    CHECK(sizeof((0, s)) == sizeof(short));
    CHECK(sizeof((c, s)) == sizeof(short));
    CHECK(sizeof((l, c)) == sizeof(char));
    CHECK(sizeof((c, 1L)) == sizeof(long));
    CHECK(sizeof((1, 2.0)) == sizeof(double));
    CHECK(sizeof((1, 2.0f)) == sizeof(float));
    CHECK(sizeof((1.0, 2)) == sizeof(int));
    CHECK(sizeof((0, 'a')) == sizeof(int));

    /* operands of sizeof are not evaluated */
    CHECK(sizeof((z++, z)) == sizeof(int));
    CHECK(z == 0);

    /* arrays decay to pointers when they go through a comma */
    CHECK(sizeof(arr) == 3 * sizeof(int));
    CHECK(sizeof((0, arr)) == sizeof(int *));
    CHECK(sizeof("abc") == 4);
    CHECK(sizeof((0, "abc")) == sizeof(char *));
    return 0;
}

/* 18: usual arithmetic conversions use the type of the right operand */
static int t18_arith_types(void)
{
    enum { T = 18 };
    unsigned char uc = 200;

    CHECK(!((0, 1u) > -1));          /* unsigned comparison */
    CHECK(((0, 1) > -1));            /* signed comparison   */
    CHECK(!((0, -1) < (0, 1u)));
    CHECK(((0, uc) + 100) == 300);   /* promoted to int     */
    CHECK(((1, 3) / 2) == 1);
    CHECK(((1, 3) / 2.0) == 1.5);
    CHECK(((1, 2) + 0.5) == 2.5);
    return 0;
}

/* 19: pointers */
static int t19_pointers(void)
{
    enum { T = 19 };
    int a[3] = { 1, 2, 3 };
    int *p = a;
    int x = 0, y = 5, i;
    int *q;

    CHECK(*(0, p) == 1);
    CHECK(*(p++, p) == 2);
    CHECK(p == a + 1);
    CHECK(*(p, p + 1) == 3);
    CHECK(*((0, p) + 1) == 3);
    CHECK(((0, p) == p));
    CHECK(((0, p) - (0, a)) == 1);

    *(x, &y) = 9;
    CHECK(y == 9);

    q = (0, &x);
    CHECK(q == &x);

    *(x++, &y) = 6;
    CHECK(x == 1);
    CHECK(y == 6);

    (*(0, &x))++;
    CHECK(x == 2);

    CHECK(*(i = 1, a + i) == 2);
    CHECK((0, a)[2] == 3);
    CHECK(*(0, a) == 1);
    return 0;
}

/* 20: string literals */
static int t20_strings(void)
{
    enum { T = 20 };
    const char *s = (0, "hello");
    const char *names[] = { "a", "b" };

    CHECK(s[1] == 'e');
    CHECK(("ab", "cd")[1] == 'd');
    CHECK(*("x", "yz") == 'y');
    CHECK(names[(0, 1)][0] == 'b');
    return 0;
}

/* 21: structs - member access, assignment, passing, returning */
static int t21_struct_values(void)
{
    enum { T = 21 };
    struct pt p = { 3, 4 };
    struct pt q;

    CHECK((0, p).x == 3);
    CHECK((p, p).y == 4);

    q = (0, p);
    CHECK(q.x == 3);
    CHECK(q.y == 4);

    g_val = 0;
    q = (g_val = 1, make_pt(7, 8));
    CHECK(g_val == 1);
    CHECK(q.x == 7);
    CHECK(q.y == 8);

    CHECK((0, make_pt(5, 6)).y == 6);
    CHECK((g_val = 2, make_pt(1, 2)).x == 1);
    CHECK(pt_sum((0, p)) == 7);
    CHECK(pt_sum((g_val = 2, make_pt(1, 2))) == 3);
    CHECK(sizeof((0, p)) == sizeof(struct pt));

    CHECK((p.x = 10, p).x == 10);
    CHECK(p.x == 10);

    CHECK((0, &p)->x == 10);
    (0, &p)->y = 9;
    CHECK(p.y == 9);
    return 0;
}

/* 22: arrays of structs and struct containing arrays */
static int t22_struct_arrays(void)
{
    enum { T = 22 };
    struct pt arr[2] = { { 1, 2 }, { 3, 4 } };
    struct A { int v[3]; } sa = { { 5, 6, 7 } };

    CHECK(arr[(0, 1)].x == 3);
    CHECK((0, arr)[1].y == 4);
    CHECK(sa.v[(0, 2)] == 7);
    CHECK((0, sa).v[1] == 6);
    return 0;
}

/* 23: struct declarations - member declarators, bit-fields, initializers */
static int t23_struct_declarations(void)
{
    enum { T = 23 };
    struct S1 { int a, b; char c, d; } s1 = { 1, 2, 3, 4 }, s2 = { 5, 6, 7, 8 };
    CHECK(s1.a == 1 && s1.b == 2 && s1.c == 3 && s1.d == 4);
    CHECK(s2.a == 5 && s2.b == 6 && s2.c == 7 && s2.d == 8);

    struct BF { unsigned a : 3, b : 5; } bf;
    bf.a = (1, 5);
    bf.b = (2, 17);
    CHECK(bf.a == 5);
    CHECK(bf.b == 17);

    struct pt p2 = { (1, 2), (3, 4) };
    CHECK(p2.x == 2);
    CHECK(p2.y == 4);

    struct pt p3 = { .y = (0, 9), .x = (0, 8) };
    CHECK(p3.x == 8);
    CHECK(p3.y == 9);

    struct R { struct pt a, b; } r = { { (0, 1), (0, 2) }, { (0, 3), (0, 4) } };
    CHECK(r.a.x == 1);
    CHECK(r.a.y == 2);
    CHECK(r.b.x == 3);
    CHECK(r.b.y == 4);

    struct pt pa = { 1, 2 }, *pp = &pa, parr[2] = { { 1, 2 }, { 3, 4 } };
    CHECK(pp->y == 2);
    CHECK(parr[(0, 1)].y == 4);

    struct pt pc = (struct pt){ (3, 4), 5 };
    CHECK(pc.x == 4);
    CHECK(pc.y == 5);
    return 0;
}

/* 24: unions and enums */
static int t24_union_enum(void)
{
    enum { T = 24 };
    union U { int i; char c[4]; } u;
    enum E { EA, EB, EC } ev;

    u.i = (1, 7);
    CHECK(u.i == 7);

    ev = (0, EC);
    CHECK(ev == EC);
    CHECK(ev == 2);
    ev = (EA, EB);
    CHECK(ev == EB);
    return 0;
}

/* 25: declarator commas vs comma operator */
static int t25_declarations(void)
{
    enum { T = 25 };
    int a = 1, b = (2, 3), c = (4, 5), d = 0;
    CHECK(a == 1);
    CHECK(b == 3);
    CHECK(c == 5);
    CHECK(d == 0);

    int e = (6, 7), *pe = &e;
    CHECK(*pe == 7);

    int f = (1, 2), g = f + 1, h = (f, g) + 1;
    CHECK(f == 2);
    CHECK(g == 3);
    CHECK(h == 4);

    int arr1[2] = { 1, 2 }, x2 = (3, 4);
    CHECK(arr1[1] == 2);
    CHECK(x2 == 4);

    int i1 = 1, i2 = (i1, 9), i3 = i1 + i2;
    CHECK(i3 == 10);
    return 0;
}

/* 26: logical operators and short-circuit */
static int t26_logical(void)
{
    enum { T = 26 };
    int a = 0, b = 0, r;

    CHECK(((0, 1) && (0, 2)) == 1);
    CHECK(((1, 0) || (0, 0)) == 0);

    r = (a = 0, a) && (b = 1, b);
    CHECK(r == 0);
    CHECK(b == 0);     /* short-circuited */

    r = (a = 1, a) || (b = 1, b);
    CHECK(r == 1);
    CHECK(b == 0);     /* short-circuited */

    r = (a = 0, 0) || (b = 1, 2);
    CHECK(r == 1);
    CHECK(b == 1);

    CHECK(!(0, 1) == 0);
    CHECK(!(1, 0) == 1);

    /* comma and logical operators combined */
    a = 0;
    r = (a = 1, a && 0);
    CHECK(r == 0);
    r = (a = 1, a || 0);
    CHECK(r == 1);
    return 0;
}

/* 27: casts, implicit conversions and unary/binary operators */
static int t27_conversions_ops(void)
{
    enum { T = 27 };
    double d = (1, 2.5);
    float f = (1, 0.5f);
    int i = (0, 3.9);
    long l = (0, 5);
    // _Bool b1 = (0, 5);
    // _Bool b2 = (5, 0);
    // _Bool b3 = (0, 2.5);

    CHECK(d == 2.5);
    CHECK(f == 0.5f);
    CHECK(i == 3);
    CHECK(l == 5);
    // CHECK(b1 == 1);
    // CHECK(b2 == 0);
    // CHECK(b3 == 1);

    CHECK((int)(1, 2.7) == 2);
    CHECK((char)(0, 321) == 65);
    CHECK((unsigned char)(0, -1) == 255);
    CHECK((double)(0, 1) / 2 == 0.5);

    CHECK(-(1, 5) == -5);
    CHECK(~(0, 0) == -1);
    CHECK(((0, 3) * (0, 4)) == 12);
    CHECK(((1, 2) + (3, 4)) == 6);
    CHECK(((0, 1) << (0, 3)) == 8);
    CHECK(((1, 2) | (4, 8)) == 10);
    CHECK(((7, 6) & (3, 5)) == 4);
    CHECK(((7, 6) ^ (3, 5)) == 3);
    CHECK(((0, 9) % (0, 4)) == 1);
    CHECK(((0, 1) < (0, 2)) == 1);
    CHECK(((0, 1) == (1, 1)) == 1);
    return 0;
}

/* 28: assignment operators, increments */
static int t28_assign_incr(void)
{
    enum { T = 28 };
    int x = 1, y, a, b, c, r, i;

    x += (1, 2);
    CHECK(x == 3);
    x *= (0, 4);
    CHECK(x == 12);

    y = 10;
    g_val = 0;
    y -= (g_val = 3, g_val);
    CHECK(y == 7);

    a = b = (c = 1, 2);
    CHECK(a == 2);
    CHECK(b == 2);
    CHECK(c == 1);

    a = (b = 1, c = 2) + 3;
    CHECK(a == 5);
    CHECK(b == 1);
    CHECK(c == 2);

    i = 0;
    r = (i++, i++, i++);
    CHECK(r == 2);
    CHECK(i == 3);

    r = (++i, ++i);
    CHECK(r == 5);
    CHECK(i == 5);

    r = (i--, --i);
    CHECK(r == 3);
    CHECK(i == 3);
    return 0;
}

/* 29: void operands and void-typed comma expressions */
static int t29_void(void)
{
    enum { T = 29 };
    int r;

    g_val = 0;
    (set_val(1), (void)0);
    CHECK(g_val == 1);

    (void)(g_val = 4, g_val + 1);
    CHECK(g_val == 4);

    ((void)0, set_val(7));
    CHECK(g_val == 7);

    set_val(((void)0, 6));
    CHECK(g_val == 6);

    (void)0, g_val = 5;
    CHECK(g_val == 5);

    r = ((void)set_val(8), g_val);
    CHECK(r == 8);
    return 0;
}

/* 30: compound literals */
static int t30_compound_literals(void)
{
    enum { T = 30 };
    int *cp = (int[]){ (0, 5), 6 };

    CHECK((int[]){ 1, 2, 3 }[(0, 2)] == 3);
    CHECK(((struct pt){ (1, 2), (3, 4) }).y == 4);
    CHECK(cp[0] == 5);
    CHECK(cp[1] == 6);
    CHECK(sizeof((int[]){ 1, 2, 3 }) == 3 * sizeof(int));
    CHECK((0, (struct pt){ 1, 2 }).x == 1);
    CHECK(pt_sum((0, (struct pt){ 3, 4 })) == 7);
    return 0;
}

/* 31: macros */
static int t31_macros(void)
{
    enum { T = 31 };
    int a = 1, b = 2, t = 0, r;

    CHECK(PASS((1, 2)) == 2);
    CHECK(FIRST((1, 2), (3, 4)) == 2);
    CHECK(MAXV((0, 3), (0, 5)) == 5);

    r = SWAP(t, a, b);
    CHECK(a == 2);
    CHECK(b == 1);
    CHECK(t == 1);
    CHECK(r == 1);
    return 0;
}

/* 32: very long and deeply nested chains */
static int t32_long_nested(void)
{
    enum { T = 32 };
    int a, b, c, d, e, f, g, h, i, j, r;

    r = (a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8, i = 9,
         j = 10, a + b + c + d + e + f + g + h + i + j);
    CHECK(r == 55);
    CHECK(a == 1);
    CHECK(j == 10);

    CHECK((((((1, 2), 3), 4), 5)) == 5);
    CHECK((1, (2, (3, (4, 5)))) == 5);

    g_trace = 0;
    r = ((tr(1), (tr(2), tr(3))), tr(4));
    CHECK(r == 4);
    CHECK(g_trace == 1234);
    return 0;
}

/* 33: recursion */
static int t33_recursion(void)
{
    enum { T = 33 };

    g_calls = 0;
    CHECK(fact(5) == 120);
    CHECK(g_calls == 5);

    g_calls = 0;
    CHECK(fib(6) == 8);
    CHECK(g_calls == 13);   /* number of leaf calls */
    return 0;
}

/* 34: goto/labels with comma statements */
static int t34_goto(void)
{
    enum { T = 34 };
    int i = 0, n = 0;

again:
    i++, n += 2;
    if (i < 3)
        goto again;

    CHECK(i == 3);
    CHECK(n == 6);
    return 0;
}

/* 35: floating point */
static int t35_floating(void)
{
    enum { T = 35 };
    double d;
    float f;

    CHECK((d = 1.5, d * 2) == 3.0);
    CHECK(d == 1.5);
    (d = 2.0, 1);
    CHECK(d == 2.0);
    CHECK((f = 0.25f, f + f) == 0.5f);
    CHECK((1, 2.5) == 2.5);
    CHECK((2.5, 1) == 1);
    return 0;
}

/* 36: comma result is an rvalue but can be dereferenced / addressed through */
static int t36_pointer_lvalues(void)
{
    enum { T = 36 };
    int a = 0, b = 0;
    int *p;

    *(a, &b) = 5;
    CHECK(b == 5);

    p = (a++, &a);
    CHECK(a == 1);
    *p = 42;
    CHECK(a == 42);

    int arr[3] = { 0, 0, 0 };
    *(0, arr + 1) = 8;
    CHECK(arr[1] == 8);
    (0, arr)[2] = 9;
    CHECK(arr[2] == 9);
    return 0;
}

/* 37: comma in conditions mixing with function calls and structs */
static int t37_mixed(void)
{
    enum { T = 37 };
    struct pt p;
    int r;

    g_count = 0;
    p = (next(), make_pt(g_count, g_count + 10));
    CHECK(p.x == 1);
    CHECK(p.y == 11);

    g_count = 0;
    r = add((next(), 5), (next(), next()));
    CHECK(g_count == 3);
    CHECK(r == 5 + 3 || r == 5 + 2);   /* argument order is unspecified */
    return 0;
}

/* 38: if/else chain and loops using results of comma with calls */
static int t38_control_with_calls(void)
{
    enum { T = 38 };
    int i, s = 0;

    g_count = 0;
    for (i = 0; (next(), g_count) < 5; i++)
        s += g_count;
    CHECK(i == 4);
    CHECK(s == 1 + 2 + 3 + 4);

    g_count = 0;
    while ((next(), next(), g_count) < 7)
        ;
    CHECK(g_count == 8);
    return 0;
}

/* 39: comma with function-returning-struct and arrays of results */
static int t39_struct_calls(void)
{
    enum { T = 39 };
    struct pt arr[2];

    arr[(0, 0)] = (tr(1), make_pt(1, 2));
    arr[(0, 1)] = (tr(2), make_pt(3, 4));
    CHECK(arr[0].x == 1);
    CHECK(arr[0].y == 2);
    CHECK(arr[1].x == 3);
    CHECK(arr[1].y == 4);
    CHECK(pt_sum((0, arr[1])) == 7);
    return 0;
}

/* 40: static storage and qualifiers */
static int t40_qualifiers(void)
{
    enum { T = 40 };
    static int sv;
    const int ci = 5;
    volatile int vi;
    int r;

    r = (sv = 3, sv + 1);
    CHECK(r == 4);
    CHECK(sv == 3);

    r = (0, ci);
    CHECK(r == 5);

    r = (vi = 6, vi);
    CHECK(r == 6);
    return 0;
}

/* 41: comma operand being a conditional / assignment inside bigger expr */
static int t41_complex_expr(void)
{
    enum { T = 41 };
    int a = 1, b = 2, c = 3, r;

    r = (a > b ? a : b, c) * 2;
    CHECK(r == 6);

    r = ((a = 5, a) > (b = 3, b)) ? (c = 7, c) : (c = 8, c);
    CHECK(r == 7);
    CHECK(a == 5);
    CHECK(b == 3);
    CHECK(c == 7);

    r = (a = 1, b = 2, c = 3, a + b * c) - (0, 1);
    CHECK(r == 6);
    return 0;
}

/* 42: comma as a statement expression with chained assignments */
static int t42_statements(void)
{
    enum { T = 42 };
    int a = 0, b = 0, c = 0;

    a = 1, b = 2, c = a + b;
    CHECK(a == 1);
    CHECK(b == 2);
    CHECK(c == 3);

    a++, b--, c += 10;
    CHECK(a == 2);
    CHECK(b == 1);
    CHECK(c == 13);

    for (a = 0, b = 0; a < 3; a++)
        b += a, c++;
    CHECK(b == 3);
    CHECK(c == 16);
    return 0;
}

/* ------------------------------------------------------------------ */

#define RUN(f) do { int r_ = f(); if (r_) return r_; } while (0)

int main(void)
{
    RUN(t01_basic_value);
    RUN(t02_side_effects);
    RUN(t03_evaluation_order);
    RUN(t04_discarded_left);
    RUN(t05_precedence_assignment);
    RUN(t06_ternary);
    RUN(t07_for_loops);
    RUN(t08_while_dowhile);
    RUN(t09_if);
    RUN(t10_switch);
    RUN(t11_return);
    RUN(t12_call_arguments);
    RUN(t13_call_operands);
    RUN(t14_function_pointers);
    RUN(t15_array_subscript);
    RUN(t16_array_init);
    RUN(t17_types_sizeof);
    RUN(t18_arith_types);
    RUN(t19_pointers);
    RUN(t20_strings);
    RUN(t21_struct_values);
    RUN(t22_struct_arrays);
    RUN(t23_struct_declarations);
    RUN(t24_union_enum);
    RUN(t25_declarations);
    RUN(t26_logical);
    RUN(t27_conversions_ops);
    RUN(t28_assign_incr);
    RUN(t29_void);
    RUN(t30_compound_literals);
    RUN(t31_macros);
    RUN(t32_long_nested);
    RUN(t33_recursion);
    RUN(t34_goto);
    RUN(t35_floating);
    RUN(t36_pointer_lvalues);
    RUN(t37_mixed);
    RUN(t38_control_with_calls);
    RUN(t39_struct_calls);
    RUN(t40_qualifiers);
    RUN(t41_complex_expr);
    RUN(t42_statements);
    return 0;
}