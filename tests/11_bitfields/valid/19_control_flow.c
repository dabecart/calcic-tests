/*
 * TEST: control_flow
 * Bit-fields as controlling expressions: if/while/for/do/switch, ternary, &&, ||, !.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned n : 4; signed int k : 4; unsigned f : 1; unsigned e : 2; };

int main(void)
{
    struct S s = {0, 0, 0, 0};
    int cnt, sum, r, x;

    s.f = 1;
    if (!s.f) return 1;
    s.f = 0;
    if (s.f) return 2;
    x = s.f ? 10 : 20;
    CHECK(x == 20);
    s.f = 1; s.n = 0;
    CHECK(!(s.f && s.n));
    CHECK(s.f || s.n);
    CHECK((s.n || s.f) == 1);
    CHECK(!s.n);

    s.n = 9; cnt = 0;
    while (s.n) { s.n--; cnt++; }
    CHECK(cnt == 9 && s.n == 0);

    sum = 0;
    for (s.n = 0; s.n < 10; s.n++) sum += s.n;
    CHECK(sum == 45 && s.n == 10);

    s.n = 5; cnt = 0;
    do { cnt++; } while (--s.n);
    CHECK(cnt == 5);

    r = 0;
    for (s.k = -3; s.k <= 3; s.k++) {
        switch (s.k) {
        case -2: r += 1; break;
        case 0:  r += 10; break;
        case 3:  r += 100; break;
        default: r += 1000; break;
        }
    }
    CHECK(r == 4111);

    r = 0;
    s.e = 2;
    switch (s.e) {
    case 0: r += 1;
    case 1: r += 10;
    case 2: r += 100;
    case 3: r += 1000;
    }
    CHECK(r == 1100);
    return 0;
}
