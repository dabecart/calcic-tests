/*
 * TEST: many_arguments_stack
 * Calls with many arguments (forcing stack passing) mixing bit-field values and
 * bit-field structs by value; recursion with rotating argument lists.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 5; signed int b : 9; unsigned c : 3; };

static int total(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10)
{
    return i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10;
}
static int fs(struct S s) { return (int)s.a + s.b + (int)s.c; }
static int mix(struct S a, int i1, struct S b, int i2, struct S c, int i3,
               struct S d, int i4, struct S e, int i5)
{
    return fs(a) + 2 * fs(b) + 3 * fs(c) + 4 * fs(d) + 5 * fs(e)
         + i1 + 2 * i2 + 3 * i3 + 4 * i4 + 5 * i5;
}
static int deep(int n, struct S s, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    if (n == 0) return (int)s.a + s.b + a7;
    s.a++;
    return deep(n - 1, s, a2, a3, a4, a5, a6, a7, a1);
}

int main(void)
{
    struct S s = {3, -100, 5};
    struct S s1 = {1, -10, 1}, s2 = {2, -20, 2}, s3 = {3, -30, 3}, s4 = {4, -40, 4}, s5 = {5, -50, 5};

    CHECK(total(s.a, s.b, s.c, 4, 5, 6, 7, 8, 9, 10) == -43);
    CHECK(total(s.c, s.c, s.c, s.a, s.a, s.a, 1, 1, 1, 1) == 28);
    CHECK(mix(s1, 1, s2, 2, s3, 3, s4, 4, s5, 5) == -385);
    CHECK(deep(7, s, 1, 2, 3, 4, 5, 6, 7) == -83);
    CHECK(deep(3, s, 1, 2, 3, 4, 5, 6, 7) == -91);
    return 0;
}
