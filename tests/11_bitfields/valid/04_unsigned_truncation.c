/*
 * TEST: unsigned_truncation
 * Assigning out-of-range values to unsigned bit-fields reduces them modulo
 * 2^width (well defined); neighbours must not be corrupted by the overflow.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 3; unsigned b : 12; unsigned c : 1; };

int main(void)
{
    struct S s = {0, 0, 0};

    s.a = 8;          CHECK(s.a == 0);
    s.a = 9;          CHECK(s.a == 1);
    s.a = 15;         CHECK(s.a == 7);
    s.a = 0xFFFFFFFFu; CHECK(s.a == 7);
    s.a = -1;         CHECK(s.a == 7);
    s.b = 0x1FFF;     CHECK(s.b == 0xFFF);
    s.b = 4096;       CHECK(s.b == 0);
    s.b = 4097;       CHECK(s.b == 1);
    s.c = 2;          CHECK(s.c == 0);
    s.c = 3;          CHECK(s.c == 1);
    s.c = -1;         CHECK(s.c == 1);

    s.a = 7; s.b = 0x123; s.c = 1;
    s.a = 8 + 2;
    CHECK(s.a == 2 && s.b == 0x123 && s.c == 1);
    s.b = 0x10000 + 0x456;
    CHECK(s.a == 2 && s.b == 0x456 && s.c == 1);
    s.c = 4;
    CHECK(s.a == 2 && s.b == 0x456 && s.c == 0);
    return 0;
}
