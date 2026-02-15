// Exit code: 0
struct S { int val; };
typedef struct S S_alias;

int main(void) {
    struct S s1 = {1};
    S_alias s2 = {2};
    s1 = s2;
    if (s1.val != 2) return 1;
    return 0;
}