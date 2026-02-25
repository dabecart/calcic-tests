// Exit code: 0
#include <string.h>

/* Test basic non-overlapping copy */
int test_basic() {
    char d[10] = {0};
    memcpy(d, "hello", 6);
    return strcmp(d, "hello") == 0 ? 0 : 1;
}

/* Test zero-byte copy (should not modify destination) */
int test_zero_bytes() {
    char d[10] = "world";
    memcpy(d, "hello", 0);
    return strcmp(d, "world") == 0 ? 0 : 1;
}

int main(void) {
    if (test_basic() != 0) return 1;
    if (test_zero_bytes() != 0) return 2;
    return 0;
}
