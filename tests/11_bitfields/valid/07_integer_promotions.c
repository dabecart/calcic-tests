/*
 * TEST: integer_promotions
 * Integer promotions of bit-fields (C99 6.3.1.1): a bit-field whose values all fit
 * in int promotes to int, an unsigned :32 field stays unsigned int.  Also usual
 * arithmetic conversions and comparisons mixing signedness.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 3; unsigned b : 31; unsigned c : 32; signed int d : 5; };

int main(void)
{
    struct S s = {0, 0, 0, 0};

    s.a = 2; s.b = 1; s.c = 1; s.d = -3;
    CHECK((s.a - 5) < 0);          /* :3 promotes to int */
    CHECK(-s.a == -2);
    CHECK(~s.a == -3);
    CHECK((s.b - 2) < 0);          /* :31 fits in int */
    CHECK((s.c - 2) > 0);          /* :32 stays unsigned int */
    CHECK(s.d + 1 == -2);

    s.a = 7;
    CHECK(s.a + s.a == 14);        /* no wrap at 3 bits */
    CHECK((s.a << 3) == 56);
    CHECK(s.a * 100 == 700);
    CHECK((1 ? s.a : -1) - 10 < 0);

    s.a = 2;
    CHECK((s.a - 5u) > 0);         /* int op unsigned -> unsigned */
    CHECK(-1 < s.a);               /* both int */

    s.d = -1;
    CHECK((s.d < 0u) == 0);        /* -1 converted to unsigned */
    CHECK(s.d > 1u);
    CHECK(s.d < 0);
    return 0;
}
