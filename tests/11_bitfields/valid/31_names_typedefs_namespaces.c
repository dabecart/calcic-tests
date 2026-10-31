/*
 * TEST: names_typedefs_namespaces
 * Bit-field names live in their own namespace: they may coincide with tags,
 * variables, functions, labels and typedef names.  Typedef'd bit-field structs.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

typedef struct { unsigned x : 3; signed int y : 4; } T1;
typedef struct tag2 { unsigned x : 5; unsigned tag2 : 6; } T2;
struct x { unsigned x : 2; };
struct W { unsigned T1 : 5; unsigned func : 3; };
typedef T1 *PT1;

static int func(void) { return 41; }

int main(void)
{
    T1 a = {5, -3};
    T2 b = {17, 40};
    struct x c = {3};
    struct W w;
    PT1 pa = &a;
    int x = 5;
    int tag2 = 9;

    CHECK(a.x == 5 && a.y == -3);
    CHECK(b.x == 17 && b.tag2 == 40);
    c.x = x;
    CHECK(c.x == 1);
    w.T1 = 31; w.func = 7;
    CHECK(w.T1 == 31 && w.func == 7);
    CHECK(func() == 41);
    pa->x = 7; pa->y = 3;
    CHECK(a.x == 7 && a.y == 3);
    b.tag2 = tag2;
    CHECK(b.tag2 == 9 && x == 5);
    goto x;
    return 1;
x:
    return 0;
}
