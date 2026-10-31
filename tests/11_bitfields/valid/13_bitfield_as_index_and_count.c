/*
 * TEST: bitfield_as_index_and_count
 * Bit-field values used as array subscripts, pointer offsets (also negative),
 * shift counts, loop bounds and string indices.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct S { unsigned i : 4; signed int k : 4; unsigned n : 3; };

static int arr[16];

int main(void)
{
    struct S s = {0, 0, 0};
    int *p;
    int i, sum;
    int m[4][4];

    for (i = 0; i < 16; i++) arr[i] = i * i;

    s.i = 7;   CHECK(arr[s.i] == 49);
    s.i = 15;  CHECK(arr[s.i] == 225);
    p = arr + 8; s.k = -3;
    CHECK(p[s.k] == 25);
    s.n = 5;
    CHECK(*(arr + s.n) == 25 && *(p + s.n) == 169);
    CHECK((p + s.n) - p == 5);

    s.n = 3;
    CHECK((1 << s.n) == 8);
    sum = 0;
    for (i = 0; i < s.n; i++) sum += arr[i];
    CHECK(sum == 5);

    m[s.n][s.i - 12] = 42;
    CHECK(m[3][3] == 42);
    arr[s.i]++;
    CHECK(arr[15] == 226);
    CHECK(arr[s.i - s.n] == 144);
    CHECK("abcdefgh"[s.n] == 'd');
    return 0;
}
