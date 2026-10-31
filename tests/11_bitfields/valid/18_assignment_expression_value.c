/*
 * TEST: assignment_expression_value
 * The value of an assignment expression whose left operand is a bit-field is the
 * value of the bit-field after the assignment (i.e. truncated), chains across
 * different widths, compound forms, comma operator, use inside conditions.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned u3 : 3; signed int s4 : 4; unsigned c1 : 1; unsigned w12 : 12; };

int main(void)
{
    struct S s = {0, 0, 0, 0};
    struct S t = {0, 0, 0, 0};
    int x;

    x = (s.u3 = 9);            CHECK(x == 1 && s.u3 == 1);
    x = (s.u3 = -1);           CHECK(x == 7 && s.u3 == 7);
    x = (s.s4 = 5);            CHECK(x == 5 && s.s4 == 5);
    x = s.u3 = s.w12 = 0x1234; CHECK(x == 4 && s.w12 == 0x234 && s.u3 == 4);
    t.u3 = s.w12 = 0x1FFF;     CHECK(s.w12 == 0xFFF && t.u3 == 7);
    CHECK(((s.u3 = 10) + 1) == 3);
    if ((s.c1 = 2) == 0) x = 1; else x = 0;
    CHECK(x == 1);
    x = (s.u3 = 1, s.u3 + 1);  CHECK(x == 2);
    s.u3 = 1;
    x = (s.u3 += 20);          CHECK(x == 5 && s.u3 == 5);
    x = (s.s4 -= 2);           CHECK(x == 3 && s.s4 == 3);
    CHECK(s.w12 == 0xFFF && s.c1 == 0);
    return 0;
}
