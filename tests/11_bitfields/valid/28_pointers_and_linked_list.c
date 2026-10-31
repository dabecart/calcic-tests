/*
 * TEST: pointers_and_linked_list
 * Structs with bit-fields and pointers: linked list traversal, in-place reversal,
 * pointer-to-pointer walking, pointer differences, tags updated through pointers.
 *
 * Expected: compiles, runs, exits with status 0.
 * A failing CHECK makes main return (line number % 255) + 1.
 */
#define CHECK(...) do { if (!(__VA_ARGS__)) return (__LINE__ % 255) + 1; } while (0)

struct Node { unsigned val : 6; struct Node *next; signed int w : 5; unsigned tag : 2; };

static struct Node nodes[5];

int main(void)
{
    struct Node *head, *p, *prev, *nx;
    struct Node **pp;
    int i, sum, wsum, cnt;

    for (i = 0; i < 5; i++) {
        nodes[i].val = i * 10;
        nodes[i].w = i - 2;
        nodes[i].tag = i & 3;
        nodes[i].next = (i < 4) ? &nodes[i + 1] : 0;
    }
    head = &nodes[0];

    sum = wsum = cnt = 0;
    for (p = head; p; p = p->next) { sum += p->val; wsum += p->w; cnt++; }
    CHECK(sum == 100 && wsum == 0 && cnt == 5);
    CHECK(head->next->next->val == 20);
    CHECK(head->next->next->next->next->w == 2);
    CHECK(&nodes[4] - head == 4);

    for (pp = &head; *pp; pp = &(*pp)->next)
        (*pp)->tag ^= 1;
    CHECK(nodes[0].tag == 1 && nodes[1].tag == 0 && nodes[2].tag == 3 &&
          nodes[3].tag == 2 && nodes[4].tag == 1);
    CHECK(nodes[2].val == 20 && nodes[4].w == 2);

    prev = 0;
    for (p = head; p; p = nx) { nx = p->next; p->next = prev; prev = p; }
    head = prev;
    CHECK(head == &nodes[4]);
    for (i = 4, p = head; p; p = p->next, i--)
        CHECK(p->val == i * 10 && p->w == i - 2);
    CHECK(i == -1);
    return 0;
}
