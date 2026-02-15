// Exit code: 0
struct S { char c; int i; };
typedef struct S S;
int main(void) {
    // Basic sanity check, padding might vary but should be >= sum
    if (sizeof(S) < sizeof(char) + sizeof(int)) return 1;
    return 0;
}