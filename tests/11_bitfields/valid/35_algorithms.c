/*
 * TEST: algorithms
 * Small algorithms over bit-field data: bubble sort of structs by a bit-field key,
 * sieve of Eratosthenes with 1-bit flags, 8-bit wrapping checksum accumulators.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct Item { unsigned key : 7; signed int val : 9; };
struct Flag { unsigned composite : 1; };
struct Acc { unsigned sum : 8; unsigned count : 8; };

static struct Flag sieve[100];

int main(void)
{
    struct Item items[6] = { {5, 10}, {3, -20}, {9, 30}, {1, -40}, {7, 50}, {2, -60} };
    int ekey[6] = {1, 2, 3, 5, 7, 9};
    int eval[6] = {-40, -60, -20, 10, 50, 30};
    struct Acc acc = {0, 0};
    unsigned expect = 0;
    int i, j, primes;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5 - i; j++)
            if (items[j].key > items[j + 1].key) {
                struct Item t = items[j]; items[j] = items[j + 1]; items[j + 1] = t;
            }
    for (i = 0; i < 6; i++) CHECK(items[i].key == ekey[i] && items[i].val == eval[i]);

    for (i = 2; i < 100; i++)
        if (!sieve[i].composite)
            for (j = i * 2; j < 100; j += i) sieve[j].composite = 1;
    primes = 0;
    for (i = 2; i < 100; i++) if (!sieve[i].composite) primes++;
    CHECK(primes == 25);

    for (i = 0; i < 1000; i++) {
        acc.sum += i;
        acc.count++;
        expect = (expect + i) & 0xFF;
    }
    CHECK(acc.sum == expect && acc.count == 1000 % 256);
    return 0;
}
