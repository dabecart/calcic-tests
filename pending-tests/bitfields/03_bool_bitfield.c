/*
 * TEST: bool_bitfield
 * _Bool bit-fields: conversion is "non-zero -> 1" (not truncation), ++, |=, use
 * in conditions and arithmetic.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct F { _Bool a : 1; unsigned mid : 3; _Bool b : 1; };

int main(void)
{
    struct F f = {0, 0, 0};

    f.a = 1;
    CHECK(f.a == 1 && f.mid == 0 && f.b == 0);
    f.b = 1;
    CHECK(f.a == 1 && f.b == 1 && f.mid == 0);
    f.mid = 5;
    CHECK(f.a == 1 && f.b == 1 && f.mid == 5);
    f.a = 0;
    CHECK(f.a == 0 && f.b == 1 && f.mid == 5);

    f.a = 2;     CHECK(f.a == 1);
    f.a = 256;   CHECK(f.a == 1);
    f.a = -1;    CHECK(f.a == 1);
    f.a = 0.25;  CHECK(f.a == 1);
    f.a = 0.0;   CHECK(f.a == 0);
    f.b = 1024;  CHECK(f.b == 1 && f.a == 0 && f.mid == 5);

    f.a = 0; f.a++;
    CHECK(f.a == 1);
    f.a = 0; f.a |= 2;
    CHECK(f.a == 1);
    f.a = 1; f.a &= 0;
    CHECK(f.a == 0);

    f.a = 1; f.b = 1;
    CHECK(f.a + f.b == 2);
    CHECK((f.a && f.b) == 1);
    f.b = 0;
    CHECK(!f.b && f.a);
    CHECK(f.a ? 1 : 0);

    f.mid = 6; f.a = f.mid;
    CHECK(f.a == 1);
    f.mid = 0; f.a = f.mid;
    CHECK(f.a == 0);
    CHECK(f.mid == 0 && f.b == 0);
    return 0;
}
