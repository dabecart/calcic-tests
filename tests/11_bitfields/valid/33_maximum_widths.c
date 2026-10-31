/*
 * TEST: maximum_widths
 * Fields as wide as their declared type (32 bits) and 31 bits: extreme values,
 * wrap-around of unsigned :32, independence of neighbouring 32-bit fields.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned u : 32; signed int i : 32; unsigned t : 31; signed int v : 31; };

int main(void)
{
    struct S s = {0, 0, 0, 0};

    s.u = 0xFFFFFFFFu;
    CHECK(s.u == 0xFFFFFFFFu && s.i == 0);
    s.u++;
    CHECK(s.u == 0);
    s.u--;
    CHECK(s.u == 0xFFFFFFFFu);
    s.u = 0x80000000u;
    CHECK((s.u >> 31) == 1u);
    s.u += 0x80000000u;
    CHECK(s.u == 0);

    s.i = -2147483647 - 1;
    CHECK(s.i == -2147483647 - 1 && s.u == 0);
    s.i = 2147483647;
    CHECK(s.i == 2147483647);
    s.i = -1;
    CHECK(s.i == -1 && s.t == 0 && s.v == 0);

    s.t = 0x7FFFFFFFu;
    CHECK(s.t == 0x7FFFFFFFu);
    s.t = s.t + 1u;
    CHECK(s.t == 0);
    s.t = 0xFFFFFFFFu;
    CHECK(s.t == 0x7FFFFFFFu && s.v == 0);

    s.v = -1073741823 - 1;
    CHECK(s.v == -1073741823 - 1 && s.t == 0x7FFFFFFFu);
    s.v = 1073741823;
    CHECK(s.v == 1073741823);
    CHECK(s.i == -1);
    return 0;
}
