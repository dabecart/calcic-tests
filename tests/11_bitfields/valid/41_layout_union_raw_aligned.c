/*
 * TEST: layout_union_raw_aligned
 * LAYOUT (little endian, allocation from the LSB): bit positions of unit-aligned
 * fields observed through an overlapping unsigned / byte array.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

union A { unsigned raw; struct { unsigned a : 8; unsigned b : 8; unsigned c : 16; } f; };
union B { unsigned raw; struct { signed int a : 4; signed int b : 12; signed int c : 16; } f; };
union D { unsigned raw[2]; struct { unsigned a : 20; unsigned b : 20; } f; };

int main(void)
{
    union A u;
    union B v;
    union D d;

    u.raw = 0;
    u.f.a = 0x12; u.f.b = 0x34; u.f.c = 0x5678;
    CHECK(u.raw == 0x56783412u);
    u.raw = 0xA1B2C3D4u;
    CHECK(u.f.a == 0xD4 && u.f.b == 0xC3 && u.f.c == 0xA1B2);

    v.raw = 0;
    v.f.a = -1;
    CHECK(v.raw == 0xFu);
    v.f.b = -1;
    CHECK(v.raw == 0xFFFFu);
    v.f.c = -1;
    CHECK(v.raw == 0xFFFFFFFFu);
    v.raw = 0x8000F0F7u;
    CHECK(v.f.a == 7 && v.f.b == -241 && v.f.c == -32768);

    d.raw[0] = 0; d.raw[1] = 0;
    d.f.a = 0xABCDE; d.f.b = 0x12345;
    CHECK(d.raw[0] == 0xABCDEu && d.raw[1] == 0x12345u);
    CHECK(sizeof(union D) == 8);
    return 0;
}
