/*
 * TEST: mixed_members
 * Bit-fields interleaved with char/short/int/double members (unaligned case):
 * writes to ordinary members must not clobber bit-fields and vice versa.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct M {
    char c;
    unsigned a : 3;
    short s;
    unsigned b : 12;
    int i;
    unsigned c2 : 7;
    double d;
    unsigned char tail;
};

static struct M m;

int main(void)
{
    struct M k;
    int j;

    m.c = 'x'; m.a = 5; m.s = -1234; m.b = 0xABC; m.i = -99999; m.c2 = 100;
    m.d = 2.5; m.tail = 250;
    CHECK(m.c == 'x' && m.a == 5 && m.s == -1234 && m.b == 0xABC);
    CHECK(m.i == -99999 && m.c2 == 100 && m.d == 2.5 && m.tail == 250);

    m.c = 'y'; m.s = 77; m.i = 5; m.tail = 1;
    CHECK(m.a == 5 && m.b == 0xABC && m.c2 == 100);
    m.a = 2; m.b = 0x123; m.c2 = 1;
    CHECK(m.c == 'y' && m.s == 77 && m.i == 5 && m.d == 2.5 && m.tail == 1);

    for (j = 0; j < 8; j++) {
        m.a = j; m.s = (short)-j; m.b = j * 500; m.i = j * 100000; m.c2 = j * 10;
        m.c = (char)('a' + j); m.tail = (unsigned char)(255 - j);
        CHECK(m.a == j && m.s == -j && m.b == j * 500 && m.i == j * 100000);
        CHECK(m.c2 == j * 10 && m.c == 'a' + j && m.tail == 255 - j);
    }

    CHECK((char *)&m.s > (char *)&m.c);
    CHECK((char *)&m.i > (char *)&m.s);
    CHECK((char *)&m.d > (char *)&m.i);
    CHECK((char *)&m.tail > (char *)&m.d);

    k = m;
    k.a = 0; k.s = 0;
    CHECK(m.a == 7 && m.s == -7 && k.b == 3500 && k.c2 == 70 && k.tail == 248);
    return 0;
}
