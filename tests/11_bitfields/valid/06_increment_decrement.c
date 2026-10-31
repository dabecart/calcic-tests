/*
 * TEST: increment_decrement
 * Prefix/postfix ++ and -- on bit-fields: result values, wrap-around of unsigned
 * fields, loops, neighbours untouched.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned a : 3; signed int b : 4; unsigned c : 2; };

int main(void)
{
    struct S s = {0, 0, 0};
    int x, i;

    s.a = 6;
    x = s.a++;  CHECK(x == 6 && s.a == 7);
    x = s.a++;  CHECK(x == 7 && s.a == 0);
    x = s.a--;  CHECK(x == 0 && s.a == 7);
    x = ++s.a;  CHECK(x == 0 && s.a == 0);
    x = --s.a;  CHECK(x == 7 && s.a == 7);

    s.b = -1;
    x = s.b++;  CHECK(x == -1 && s.b == 0);
    x = s.b--;  CHECK(x == 0 && s.b == -1);
    s.b = 7;
    x = --s.b;  CHECK(x == 6 && s.b == 6);
    s.b = -7;
    x = ++s.b;  CHECK(x == -6 && s.b == -6);

    s.c = 0;
    for (i = 0; i < 10; i++) s.c++;
    CHECK(s.c == 2);
    for (i = 0; i < 10; i++) s.c--;
    CHECK(s.c == 0);

    s.a = 5; s.b = -3; s.c = 1;
    s.a++; s.b--; s.c++;
    CHECK(s.a == 6 && s.b == -4 && s.c == 2);
    --s.a; ++s.b; --s.c;
    CHECK(s.a == 5 && s.b == -3 && s.c == 1);
    return 0;
}
