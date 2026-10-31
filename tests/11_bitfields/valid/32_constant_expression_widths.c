/*
 * TEST: constant_expression_widths
 * Widths given by enum constants, macros, sizeof and constant expressions; enum
 * values stored in and compared with bit-fields; switch on a bit-field.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

enum { W3 = 3, W5 = 5, W12 = 12 };
#define W_EXPR (W5 + 2)
enum Color { RED, GREEN, BLUE = 6 };

struct S {
    unsigned a : W3;
    unsigned b : W_EXPR;
    unsigned c : sizeof(int) * 2;
    unsigned d : (1 ? 4 : 9);
    signed int e : 2 + 1;
    unsigned : W5;
    unsigned f : W12;
};

int main(void)
{
    struct S s = {0, 0, 0, 0, 0, 0};
    unsigned cmask = (1u << (sizeof(int) * 2)) - 1u;
    int r = 0;

    s.a = 7;    CHECK(s.a == 7);   s.a = 8;   CHECK(s.a == 0);
    s.b = 127;  CHECK(s.b == 127); s.b = 128; CHECK(s.b == 0);
    s.c = cmask; CHECK(s.c == cmask);
    s.c = cmask + 1; CHECK(s.c == 0);
    s.d = 15;   CHECK(s.d == 15);  s.d = 16;  CHECK(s.d == 0);
    s.e = -4;   CHECK(s.e == -4);  s.e = 3;   CHECK(s.e == 3);
    s.f = 4095; CHECK(s.f == 4095); s.f = 4096; CHECK(s.f == 0);
    CHECK(s.e == 3 && s.d == 0 && s.b == 0);

    s.a = BLUE;
    CHECK(s.a == BLUE);
    switch (s.a) {
    case RED:   r = 1; break;
    case GREEN: r = 2; break;
    case BLUE:  r = 3; break;
    }
    CHECK(r == 3);
    s.a = GREEN;
    CHECK(s.a == GREEN && s.a != BLUE);
    return 0;
}
