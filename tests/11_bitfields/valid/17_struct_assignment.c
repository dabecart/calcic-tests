/*
 * TEST: struct_assignment
 * Whole-struct assignment/copy of structs with bit-fields (incl. unnamed members
 * and nested structs): value semantics, self-assignment, swaps, chains.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 4; signed int b : 6; unsigned : 3; unsigned c : 7; };
struct O { unsigned x : 3; struct S in; unsigned y : 3; };

int main(void)
{
    struct S s = {5, -6, 100};
    struct S t, u, v, w;
    struct S arr[4];
    struct S *p, *q;
    struct O o1 = {2, {9, -9, 9}, 6};
    struct O o2;
    int i;

    t = s;
    CHECK(t.a == 5 && t.b == -6 && t.c == 100);
    t.a = 1; t.b = 2; t.c = 3;
    CHECK(s.a == 5 && s.b == -6 && s.c == 100);

    u = v = w = s;
    CHECK(u.a == 5 && v.b == -6 && w.c == 100);

    s = s;
    CHECK(s.a == 5 && s.b == -6 && s.c == 100);

    p = &s; q = &t;
    *q = *p;
    CHECK(t.a == 5 && t.b == -6 && t.c == 100);
    q->a = 15;
    CHECK(t.a == 15 && s.a == 5);

    {   /* swap through a temporary */
        struct S x = {1, 1, 1}, y = {2, -2, 2}, tmp;
        tmp = x; x = y; y = tmp;
        CHECK(x.a == 2 && x.b == -2 && x.c == 2 && y.a == 1 && y.b == 1 && y.c == 1);
    }

    for (i = 0; i < 4; i++) { arr[i].a = i; arr[i].b = -i; arr[i].c = i * 30; }
    arr[0] = arr[3];
    CHECK(arr[0].a == 3 && arr[0].b == -3 && arr[0].c == 90 && arr[1].a == 1);
    arr[3] = arr[1]; arr[1] = arr[2];
    CHECK(arr[3].a == 1 && arr[1].a == 2);

    t = (1 ? s : u);
    CHECK(t.a == 5);
    t = (0 ? s : arr[2]);
    CHECK(t.a == 2 && t.b == -2 && t.c == 60);

    o2 = o1;
    CHECK(o2.x == 2 && o2.in.a == 9 && o2.in.b == -9 && o2.in.c == 9 && o2.y == 6);
    o2.in = s;
    CHECK(o2.in.a == 5 && o2.x == 2 && o2.y == 6 && o1.in.a == 9);
    return 0;
}
