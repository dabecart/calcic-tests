/*
 * TEST: compound_assignment
 * All compound assignment operators on unsigned and signed bit-fields,
 * including operands that are themselves bit-fields.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 4; unsigned b : 6; signed int c : 5; };

int main(void)
{
    struct S s = {0, 33, 0};

    s.a = 3;  
    s.a += 4;              CHECK(s.a == 7);
    s.a += 10;             CHECK(s.a == 1);   /* 17 mod 16 */
    s.a -= 2;              CHECK(s.a == 15);  /* -1 mod 16 */
    s.a *= 3;              CHECK(s.a == 13);  /* 45 mod 16 */
    s.a /= 2;              CHECK(s.a == 6);
    s.a %= 4;              CHECK(s.a == 2);
    s.a <<= 3;             CHECK(s.a == 0);   /* 16 mod 16 */
    s.a = 15; s.a >>= 2;   CHECK(s.a == 3);
    s.a &= 2;              CHECK(s.a == 2);
    s.a |= 5;              CHECK(s.a == 7);
    s.a ^= 15;             CHECK(s.a == 8);
    CHECK(s.b == 33);

    s.c = 3;  s.c += 4;    CHECK(s.c == 7);
    s.c -= 20;             CHECK(s.c == -13);
    s.c = -5; s.c *= 3;    CHECK(s.c == -15);
    s.c /= 2;              CHECK(s.c == -7);  /* C99: truncation toward zero */
    s.c %= 4;              CHECK(s.c == -3);
    s.c = 6;  s.c >>= 1;   CHECK(s.c == 3);
    s.c <<= 1;             CHECK(s.c == 6);
    s.c &= 3;              CHECK(s.c == 2);
    s.c |= -4;             CHECK(s.c == -2);
    s.c ^= 1;              CHECK(s.c == -1);
    CHECK(s.a == 8 && s.b == 33);

    s.a = 9;  s.b = 40;
    s.a += s.b;            CHECK(s.a == 1 && s.b == 40);   /* 49 mod 16 */
    s.c = -3;
    s.b += s.c;            CHECK(s.b == 37 && s.c == -3);
    s.b = 5;  s.b -= 10;   CHECK(s.b == 59);               /* -5 mod 64 */
    return 0;
}
