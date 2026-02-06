// Exit code: 0
/* Test: Union sharing storage between enum and int. */
enum E { BIG = 0xFF };
union U {
    enum E e;
    int i;
};
int main() {
    union U u;
    u.e = BIG;
    if (u.i != 0xFF) return 1;
    return 0;
}