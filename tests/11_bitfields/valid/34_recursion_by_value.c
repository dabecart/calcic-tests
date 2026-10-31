/*
 * TEST: recursion_by_value
 * Recursion passing/returning bit-field structs by value: a Fibonacci sequence
 * stored in 12-bit fields (wrap-around), compared against plain arithmetic.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct P { unsigned x : 12; unsigned y : 12; };

static struct P step(struct P p)
{
    struct P q;
    q.x = p.y;
    q.y = p.x + p.y;
    return q;
}
static struct P iter(struct P p, int n) { return n == 0 ? p : iter(step(p), n - 1); }
static int depth(struct P p, int n)
{
    if (!n) return p.x;
    p.x++;
    return depth(p, n - 1);
}

int main(void)
{
    int n;
    for (n = 0; n <= 40; n++) {
        unsigned x = 0, y = 1, k;
        struct P r, z = {0, 1};
        for (k = 0; k < (unsigned)n; k++) {
            unsigned nx = y, ny = (x + y) & 0xFFF;
            x = nx; y = ny;
        }
        r = iter(z, n);
        CHECK(r.x == x && r.y == y);
    }
    {
        struct P z = {0, 0};
        CHECK(depth(z, 100) == 100);
    }
    return 0;
}
