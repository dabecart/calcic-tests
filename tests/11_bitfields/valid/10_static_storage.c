/*
 * TEST: static_storage
 * Bit-fields in static locals and file-scope variables: persistence across calls,
 * zero initialisation of static arrays.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct Counter { unsigned n : 4; unsigned calls : 8; signed int flip : 6; };

static struct Counter file_ctr;
static struct Counter zeros[4];

static int bump(void)
{
    static struct Counter local;
    local.n++;
    local.calls++;
    local.flip ^= 1;
    file_ctr.n += 3;
    return local.n;
}

static int calls_so_far(void)
{
    static struct Counter probe;      /* separate static, stays zero */
    return (int)probe.calls;
}

int main(void)
{
    int i;

    for (i = 0; i < 20; i++)
        CHECK(bump() == (i + 1) % 16);
    CHECK(file_ctr.n == 12);          /* 60 mod 16 */
    CHECK(calls_so_far() == 0);
    for (i = 0; i < 4; i++)
        CHECK(zeros[i].n == 0 && zeros[i].calls == 0 && zeros[i].flip == 0);
    zeros[2].calls = 200;
    CHECK(zeros[1].calls == 0 && zeros[2].calls == 200 && zeros[3].calls == 0);
    return 0;
}
