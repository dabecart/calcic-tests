// Exit code: 0
/* Test: Double pointer to enum. */
enum E { VAL = 99 };
int main() {
    enum E e = VAL;
    enum E *p = &e;
    enum E **pp = &p;
    if (**pp != 99) return 1;
    return 0;
}