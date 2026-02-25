// Exit code: 0
#include <string.h>

/* Test non-overlapping */
int test_non_overlap() {
    char d[10] = {0};
    memmove(d, "hello", 6);
    return strcmp(d, "hello") == 0 ? 0 : 1;
}

/* Test overlap: Dest is before Src */
int test_overlap_dest_first() {
    char s[9] = "abcdefgh";
    memmove(s, s + 2, 5); /* "cdefgfgh" */
    return strcmp(s, "cdefgfgh") == 0 ? 0 : 1;
}

/* Test overlap: Src is before Dest */
int test_overlap_src_first() {
    char s[9] = "abcdefgh";
    memmove(s + 2, s, 5); /* "ababcdeh" */
    return strcmp(s, "ababcdeh") == 0 ? 0 : 1;
}

int main(void) {
    if (test_non_overlap() != 0) return 1;
    if (test_overlap_dest_first() != 0) return 2;
    if (test_overlap_src_first() != 0) return 3;
    return 0;
}
