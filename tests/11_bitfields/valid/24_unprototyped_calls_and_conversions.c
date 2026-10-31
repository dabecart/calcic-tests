/*
 * TEST: unprototyped_calls_and_conversions
 * Default argument promotions for bit-fields passed to an unprototyped function
 * (old-style definition, obsolescent but valid C99) and parameter conversion for
 * prototyped functions with narrow parameter types.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 3; signed int b : 5; unsigned c : 16; };

int combine();
int combine(x, y, z) int x; int y; int z; { return x + y + z; }

static int narrow(char c, unsigned char u, short sh) { return c + u + sh; }

int main(void)
{
    struct S s = {7, -5, 60000};

    CHECK(combine(s.a, s.b, s.c) == 60002);
    CHECK(narrow(s.b, s.a, s.b) == -5 + 7 - 5);
    CHECK(narrow(s.a, s.a, s.a) == 21);
    return 0;
}
