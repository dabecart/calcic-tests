/*
 * TEST: large_struct_values
 * Structs larger than 16 bytes containing bit-fields, doubles, int arrays and
 * char arrays: by-value parameters, returns, arrays, copies, pointers.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct Big {
    unsigned a : 3;
    unsigned b : 30;
    signed int c : 17;
    double d;
    int arr[4];
    unsigned e : 1;
    unsigned f : 31;
    char tag[5];
};

static struct Big make_big(int k)
{
    struct Big B;
    int i;
    B.a = k & 7; B.b = k * 1000; B.c = -k * 100; B.d = k * 0.25;
    for (i = 0; i < 4; i++) B.arr[i] = k * (i + 1);
    B.e = k & 1; B.f = k * 7;
    for (i = 0; i < 4; i++) B.tag[i] = (char)('A' + k + i);
    B.tag[4] = 0;
    return B;
}

static struct Big combine(struct Big x, struct Big y)
{
    struct Big r;
    int i;
    r.a = x.a + y.a; r.b = x.b + y.b; r.c = x.c + y.c; r.d = x.d + y.d;
    for (i = 0; i < 4; i++) r.arr[i] = x.arr[i] + y.arr[i];
    r.e = x.e ^ y.e; r.f = x.f + y.f;
    for (i = 0; i < 5; i++) r.tag[i] = x.tag[i];
    return r;
}

static void scribble(struct Big b) { b.a = 0; b.b = 0; b.f = 0; b.arr[0] = -1; }

int main(void)
{
    struct Big x = make_big(3);
    struct Big y = make_big(4);
    struct Big r, v[3];
    struct Big *p;
    int i;

    CHECK(x.a == 3 && x.b == 3000 && x.c == -300 && x.d == 0.75);
    CHECK(x.arr[0] == 3 && x.arr[3] == 12 && x.e == 1 && x.f == 21);
    CHECK(x.tag[0] == 'D' && x.tag[3] == 'G' && x.tag[4] == 0);

    r = combine(x, y);
    CHECK(r.a == 7 && r.b == 7000 && r.c == -700 && r.d == 1.75);
    CHECK(r.arr[0] == 7 && r.arr[1] == 14 && r.arr[2] == 21 && r.arr[3] == 28);
    CHECK(r.e == 1 && r.f == 49 && r.tag[0] == 'D');

    scribble(x);
    CHECK(x.a == 3 && x.b == 3000 && x.f == 21 && x.arr[0] == 3);

    for (i = 0; i < 3; i++) v[i] = make_big(i + 1);
    CHECK(v[0].b == 1000 && v[1].b == 2000 && v[2].b == 3000);
    v[0] = v[2];
    CHECK(v[0].b == 3000 && v[0].c == -300 && v[0].f == 21 && v[1].b == 2000);
    p = &v[1];
    p->b += 5; p->e = 1; p->arr[3]++;
    CHECK(v[1].b == 2005 && v[1].e == 0 + 1 && v[1].arr[3] == 9 && v[1].f == 14);
    CHECK(combine(v[0], v[1]).b == 5005);
    return 0;
}
