/*
 * TEST: layout_sizeof_aligned
 * LAYOUT (System V x86-64 / gcc): sizeof of structs whose fields exactly fill
 * storage units or are separated by zero-width fields.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct A1 { unsigned a : 32; };
struct A2 { unsigned a : 16; unsigned b : 16; };
struct A3 { unsigned a : 8; unsigned b : 8; unsigned c : 8; unsigned d : 8; };
struct A4 { unsigned a : 1; unsigned b : 31; unsigned c : 32; };
struct A5 { unsigned a : 3; unsigned : 0; unsigned b : 3; };
struct A6 { unsigned a : 4; unsigned : 0; unsigned b : 4; unsigned : 0; unsigned c : 4; };
struct A7 { signed int a : 5; double d; };
struct A8 { unsigned a : 1; };
struct A9 { _Bool a : 1; _Bool b : 1; unsigned c : 6; signed int d : 24; };

int main(void)
{
    CHECK(sizeof(struct A1) == 4);
    CHECK(sizeof(struct A2) == 4);
    CHECK(sizeof(struct A3) == 4);
    CHECK(sizeof(struct A4) == 8);
    CHECK(sizeof(struct A5) == 8);
    CHECK(sizeof(struct A6) == 12);
    CHECK(sizeof(struct A7) == 16);
    CHECK(sizeof(struct A8) == sizeof(unsigned));
    CHECK(sizeof(struct A9) == 4);
    CHECK(sizeof(struct A2[3]) == 12);
    return 0;
}
