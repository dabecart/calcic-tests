// Exit code: 0
#include <string.h>

/* Test basic concatenation */
int test_basic() {
    char d[10] = "ab";
    strcat(d, "cd");
    return strcmp(d, "abcd") == 0 ? 0 : 1;
}

/* Test concat with empty source */
int test_empty_src() {
    char d[10] = "ab";
    strcat(d, "");
    return strcmp(d, "ab") == 0 ? 0 : 1;
}

int main(void) {
    if (test_basic() != 0) return 1;
    if (test_empty_src() != 0) return 2;
    return 0;
}
