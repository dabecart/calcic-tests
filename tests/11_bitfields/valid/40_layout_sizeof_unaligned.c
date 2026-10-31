/*
 * TEST: layout_sizeof_unaligned
 * LAYOUT (System V x86-64 / gcc): sizeof of structs whose fields start at arbitrary
 * bit offsets, are skipped to the next unit when they do not fit, or are mixed with
 * char/short/double members.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct U1 { unsigned a : 20; unsigned b : 20; };
struct U2 { unsigned a : 20; unsigned b : 20; unsigned c : 20; };
struct U3 { char c; unsigned a : 3; };
struct U4 { char c; unsigned a : 3; char d; };
struct U5 { char c; unsigned a : 30; };
struct U6 { unsigned a : 31; char c; };
struct U7 { unsigned a : 3; double d; };
struct U8 { short s; unsigned a : 20; };
struct U9 { unsigned a : 5; unsigned b : 9; unsigned c : 13; unsigned d : 5; };
struct UA { unsigned a : 17; unsigned b : 17; unsigned c : 17; unsigned d : 17; };

int main(void)
{
    CHECK(sizeof(struct U1) == 8);
    CHECK(sizeof(struct U2) == 12);
    CHECK(sizeof(struct U3) == 4);
    CHECK(sizeof(struct U4) == 4);
    CHECK(sizeof(struct U5) == 8);
    CHECK(sizeof(struct U6) == 8);
    CHECK(sizeof(struct U7) == 16);
    CHECK(sizeof(struct U8) == 8);
    CHECK(sizeof(struct U9) == 4);
    CHECK(sizeof(struct UA) == 16);
    return 0;
}
