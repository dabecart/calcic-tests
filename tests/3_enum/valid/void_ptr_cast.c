// Exit code: 0
/* Test: Void pointer roundtrip with enum. */
enum E { MAGIC = 123 };
int main() {
    enum E e = MAGIC;
    void *v = &e;
    enum E *p = (enum E*)v;
    if (*p != 123) return 1;
    return 0;
}