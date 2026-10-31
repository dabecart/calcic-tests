/*
 * TEST: function_args_by_pointer
 * Passing bit-field structs by pointer: modification, const pointers, arrays,
 * pointer-to-pointer, pointer returned from a function and then used.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 4; signed int b : 6; unsigned c : 2; };

static void inc(struct S *p) { p->a += 1; p->b -= 1; p->c++; }
static int get_sum(const struct S *p) { return p->a + p->b + p->c; }
static void fill(struct S *arr, int n)
{
    int i;
    for (i = 0; i < n; i++) { arr[i].a = i; arr[i].b = -i; arr[i].c = i & 3; }
}
static int total(const struct S *arr, int n)
{
    int i, t = 0;
    for (i = 0; i < n; i++) t += get_sum(&arr[i]);
    return t;
}
static void reset(struct S **pp) { (*pp)->a = 0; (*pp)->b = 0; (*pp)->c = 0; }
static void swap_a(struct S *x, struct S *y) { unsigned t = x->a; x->a = y->a; y->a = t; }
static struct S *max_a(struct S *arr, int n)
{
    int i, best = 0;
    for (i = 1; i < n; i++) if (arr[i].a > arr[best].a) best = i;
    return &arr[best];
}

int main(void)
{
    struct S s = {14, -3, 3};
    struct S arr[6];
    struct S x = {1, 1, 1}, y = {2, 2, 2};
    struct S *p = &s;

    inc(&s);
    CHECK(s.a == 15 && s.b == -4 && s.c == 0);
    inc(p);
    CHECK(s.a == 0 && s.b == -5 && s.c == 1);
    CHECK(get_sum(&s) == -4);

    fill(arr, 6);
    CHECK(total(arr, 6) == 7);
    max_a(arr, 6)->b = 20;
    CHECK(arr[5].b == 20 && arr[4].b == -4);

    p = &arr[3];
    reset(&p);
    CHECK(arr[3].a == 0 && arr[3].b == 0 && arr[3].c == 0 && arr[2].a == 2);

    swap_a(&x, &y);
    CHECK(x.a == 2 && y.a == 1 && x.b == 1 && y.b == 2);
    return 0;
}
