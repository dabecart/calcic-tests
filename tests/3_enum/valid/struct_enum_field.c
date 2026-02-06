// Exit code: 0
/* Test: Enum as a struct member. */
enum E { RED, BLUE };
struct S {
    enum E color;
    int id;
};
int main() {
    struct S s;
    s.color = BLUE;
    s.id = 55;
    if (s.color != 1) return 1;
    if (s.id != 55) return 2;
    return 0;
}