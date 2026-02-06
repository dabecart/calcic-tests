// Exit code: 0
/* Test: Complex expression involving pointer to struct with enum. */
enum E { VAL = 5 };
struct S { enum E e; };
int main() {
    struct S s = { VAL };
    struct S *p = &s;
    // Check associativity: access member 'e', add 5.
    if (p->e + 5 != 10) return 1;
    return 0;
}