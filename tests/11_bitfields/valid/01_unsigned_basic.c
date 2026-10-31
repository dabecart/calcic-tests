/*
 * TEST: unsigned_basic
 * Read/write of unsigned bit-fields; every write must leave the neighbours alone.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 3; unsigned b : 5; unsigned c : 8; unsigned d : 16; };

int main(void)
{
    struct S s = {0, 0, 0, 0};

    s.a = 5;
    CHECK(s.a == 5 && s.b == 0 && s.c == 0 && s.d == 0);
    s.b = 31;
    CHECK(s.a == 5 && s.b == 31 && s.c == 0 && s.d == 0);
    s.c = 200;
    CHECK(s.a == 5 && s.b == 31 && s.c == 200 && s.d == 0);
    s.d = 65535;
    CHECK(s.a == 5 && s.b == 31 && s.c == 200 && s.d == 65535);

    s.a = 0;
    CHECK(s.a == 0 && s.b == 31 && s.c == 200 && s.d == 65535);
    s.b = 0;
    CHECK(s.a == 0 && s.b == 0 && s.c == 200 && s.d == 65535);
    s.c = 0;
    CHECK(s.a == 0 && s.b == 0 && s.c == 0 && s.d == 65535);
    s.d = 0;
    CHECK(s.a == 0 && s.b == 0 && s.c == 0 && s.d == 0);

    s.a = 7; s.b = 31; s.c = 255; s.d = 65535;
    s.b = 0;
    CHECK(s.a == 7 && s.b == 0 && s.c == 255 && s.d == 65535);

    s.a = 2; s.b = 0x15; s.c = 0xAA; s.d = 0x5555;
    CHECK(s.a == 2 && s.b == 0x15 && s.c == 0xAA && s.d == 0x5555);
    s.a = 5; s.b = 0x0A; s.c = 0x55; s.d = 0xAAAA;
    CHECK(s.a == 5 && s.b == 0x0A && s.c == 0x55 && s.d == 0xAAAA);
    return 0;
}
