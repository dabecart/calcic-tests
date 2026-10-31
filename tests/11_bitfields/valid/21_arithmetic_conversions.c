/*
 * TEST: arithmetic_conversions
 * Conversions between bit-fields and floating point / char types / enums /
 * wider integers (only values that are representable, to stay well defined).
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 3; signed int b : 9; unsigned c : 20; signed int d : 5; };
enum E { E0, E1, E2, E3 = 6 };

int main(void)
{
    struct S s = {0, 0, 0, 0};
    double dd;
    float ff;
    char ch;
    unsigned char uc;
    signed char sc;
    unsigned long ul;
    long l;
    enum E e;

    s.a = 3.99;   CHECK(s.a == 3);
    s.a = 7.5;    CHECK(s.a == 7);
    s.b = -2.5;   CHECK(s.b == -2);
    s.b = -255.9; CHECK(s.b == -255);
    s.d = 15.999; CHECK(s.d == 15);

    s.b = -100; dd = s.b;
    CHECK(dd == -100.0);
    s.c = 1000000; ff = s.c;
    CHECK(ff == 1000000.0f);
    s.a = 7; dd = s.a / 2.0;
    CHECK(dd == 3.5);

    s.b = -1; s.d = -5; s.a = 6;
    ch = s.a;     CHECK(ch == 6);
    uc = s.b;     CHECK(uc == 255);
    sc = s.d;     CHECK(sc == -5);
    ul = s.b;     CHECK(ul == (unsigned long)-1);
    l = s.d;      CHECK(l == -5L);

    s.a = 'A';    CHECK(s.a == 1);
    s.a = (unsigned char)200; CHECK(s.a == 0);
    s.b = (unsigned char)200; CHECK(s.b == 200);

    s.a = E3;     CHECK(s.a == E3);
    e = s.a;      CHECK(e == E3);
    s.a = E1;     CHECK(s.a == 1 && (enum E)s.a == E1);
    return 0;
}
