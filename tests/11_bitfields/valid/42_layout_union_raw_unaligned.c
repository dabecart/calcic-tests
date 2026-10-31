/*
 * TEST: layout_union_raw_unaligned
 * LAYOUT (little endian, allocation from the LSB): fields at odd bit offsets that
 * cross byte boundaries, and bit-fields placed after a char member.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

union C { unsigned raw; struct { unsigned a : 3; unsigned b : 7; unsigned c : 13; unsigned d : 9; } f; };
union E { unsigned char raw[4]; struct { unsigned char c; unsigned a : 4; unsigned b : 4; } f; };

int main(void)
{
    union C u;
    union E e;

    u.raw = 0;
    u.f.a = 5; u.f.b = 0x55; u.f.c = 0x1ABC; u.f.d = 0x1A5;
    CHECK(u.raw == (5u | (0x55u << 3) | (0x1ABCu << 10) | (0x1A5u << 23)));

    u.raw = 0xDEADBEEFu;
    CHECK(u.f.a == (0xDEADBEEFu & 7u));
    CHECK(u.f.b == ((0xDEADBEEFu >> 3) & 0x7Fu));
    CHECK(u.f.c == ((0xDEADBEEFu >> 10) & 0x1FFFu));
    CHECK(u.f.d == (0xDEADBEEFu >> 23));

    e.raw[0] = 0; e.raw[1] = 0; e.raw[2] = 0; e.raw[3] = 0;
    e.f.c = 0x7F; e.f.a = 0xA; e.f.b = 0x5;
    CHECK(e.raw[0] == 0x7F && e.raw[1] == 0x5A);
    return 0;
}
