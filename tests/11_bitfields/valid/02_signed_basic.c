/*
 * TEST: signed_basic
 * Signed bit-fields: extremes of the range, sign extension on read, neighbours
 * with negative values, conversion to wider / unsigned types.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { signed int a : 4; signed int b : 7; signed int c : 1; signed int d : 20; };

int main(void)
{
    struct S s = {0, 0, 0, 0};
    int i;
    long l;
    unsigned u;

    s.a = -8;
    CHECK(s.a == -8 && s.b == 0 && s.c == 0 && s.d == 0);
    s.a = 7;
    CHECK(s.a == 7 && s.b == 0 && s.c == 0 && s.d == 0);
    s.b = -64;
    CHECK(s.a == 7 && s.b == -64 && s.c == 0 && s.d == 0);
    s.b = 63;
    CHECK(s.a == 7 && s.b == 63 && s.c == 0 && s.d == 0);
    s.c = -1;
    CHECK(s.a == 7 && s.b == 63 && s.c == -1 && s.d == 0);
    s.d = -524288;
    CHECK(s.a == 7 && s.b == 63 && s.c == -1 && s.d == -524288);
    s.d = 524287;
    CHECK(s.a == 7 && s.b == 63 && s.c == -1 && s.d == 524287);

    s.a = -1; s.b = -1; s.c = -1; s.d = -1;
    CHECK(s.a == -1 && s.b == -1 && s.c == -1 && s.d == -1);
    s.b = 0;
    CHECK(s.a == -1 && s.b == 0 && s.c == -1 && s.d == -1);
    s.c = 0;
    CHECK(s.a == -1 && s.b == 0 && s.c == 0 && s.d == -1);
    s.a = 1;
    CHECK(s.a == 1 && s.b == 0 && s.c == 0 && s.d == -1);

    s.a = -3; i = s.a;
    CHECK(i == -3);
    s.d = -100000; l = s.d;
    CHECK(l == -100000L);
    s.a = -1; u = s.a;
    CHECK(u == 0xFFFFFFFFu);
    s.a = 5; u = s.a;
    CHECK(u == 5u);
    return 0;
}
