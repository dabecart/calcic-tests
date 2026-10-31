/*
 * TEST: bitwise_and_shifts
 * Bitwise operators and shifts with bit-field operands (including a 32-bit unsigned
 * field and a signed field), shift counts from bit-fields, compound shifts.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 6; unsigned b : 6; unsigned n : 3; unsigned w : 32; signed int s : 8; };

int main(void)
{
    struct S s = {0, 0, 0, 0, 0};
    int x;

    s.a = 0x2A; s.b = 0x0F;
    CHECK((s.a & s.b) == 0x0A);
    CHECK((s.a | s.b) == 0x2F);
    CHECK((s.a ^ s.b) == 0x25);
    CHECK((~s.a & 0x3F) == 0x15);
    CHECK((s.a << 2) == 0xA8);
    CHECK((s.a >> 1) == 0x15);
    CHECK((s.a && s.b) == 1 && (s.a & 0) == 0);

    s.n = 3;
    CHECK((1 << s.n) == 8);
    CHECK((0x100 >> s.n) == 0x20);
    x = 1; x <<= s.n;
    CHECK(x == 8);
    s.a <<= s.n;
    CHECK(s.a == 0x10);

    s.w = 0x80000001u;
    CHECK((s.w >> 31) == 1u);
    CHECK((s.w << 1) == 2u);
    CHECK((s.w & 0xFFFFu) == 1u);
    CHECK(~s.w == 0x7FFFFFFEu);
    CHECK((s.w ^ s.w) == 0u);

    s.s = 0x55;
    CHECK((s.s & 0x0F) == 5);
    CHECK((s.s | 0x80) == 0xD5);
    CHECK(~s.s == -86);
    s.s = -2;
    CHECK((s.s & 0xFF) == 0xFE);
    return 0;
}
