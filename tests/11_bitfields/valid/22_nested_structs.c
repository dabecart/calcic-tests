/*
 * TEST: nested_structs
 * Bit-field structs nested in other structs and arrays; pointers to the inner
 * (non-bit-field) struct member; inner struct passed by value; copies.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct In  { unsigned y : 5; signed int z : 6; };
struct Out { unsigned x : 3; struct In in; unsigned w : 9; struct In arr[2]; };

static int in_sum(struct In i) { return (int)i.y + i.z; }

int main(void)
{
    struct Out o = {0, {0, 0}, 0, {{0, 0}, {0, 0}}};
    struct Out q;
    struct Out *p = &o;
    struct In *ip;

    o.x = 5; o.in.y = 20; o.in.z = -30; o.w = 400;
    o.arr[0].y = 1; o.arr[0].z = -1; o.arr[1].y = 31; o.arr[1].z = 31;
    CHECK(o.x == 5 && o.in.y == 20 && o.in.z == -30 && o.w == 400);
    CHECK(o.arr[0].y == 1 && o.arr[0].z == -1 && o.arr[1].y == 31 && o.arr[1].z == 31);

    ip = &o.in;
    ip->y++; ip->z += 5;
    CHECK(o.in.y == 21 && o.in.z == -25 && o.x == 5 && o.w == 400);

    CHECK(in_sum(o.in) == -4);
    CHECK(in_sum(o.arr[1]) == 62);

    o.arr[0] = o.in;
    CHECK(o.arr[0].y == 21 && o.arr[0].z == -25 && o.arr[1].y == 31);
    o.in = o.arr[1];
    CHECK(o.in.y == 31 && o.in.z == 31 && o.w == 400);

    p->in.y = 2; p->arr[1].z = -32;
    CHECK(o.in.y == 2 && o.arr[1].z == -32 && o.arr[1].y == 31);

    q = o;
    q.in.y = 0; q.arr[0].z = 0;
    CHECK(o.in.y == 2 && o.arr[0].z == -25 && q.in.z == 31 && q.w == 400);
    return 0;
}
