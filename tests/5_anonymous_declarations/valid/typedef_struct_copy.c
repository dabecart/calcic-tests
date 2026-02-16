// Exit code: 0
// Tests assignment copy semantics of tagless structs via typedef.
// Verifies that 'a = b' correctly copies all members.
typedef struct {
    int id;
    float val;
    char code;
} Record;

int main(void) {
    Record src = { 101, 2.5f, 'A' };
    Record dst;

    /* Struct copy assignment */
    dst = src;

    if (dst.id != 101) return 1;
    if (dst.val != 2.5f) return 2;
    if (dst.code != 'A') return 3;

    /* Verify independence */
    src.id = 999;
    if (dst.id != 101) return 4;

    return 0;
}
