// Exit code: 0
#include <string.h>

/* Check string transformation lengths */
int test_basic() {
    char d[20];
    size_t len = strxfrm(d, "abc", 20);
    return (len > 0) ? 0 : 1;
}

/* Null dest and 0 length checks the required buffer size */
int test_zero_len() {
    size_t len = strxfrm(NULL, "abc", 0);
    return (len > 0) ? 0 : 1;
}

int main(void) {
    if (test_basic() != 0) return 1;
    if (test_zero_len() != 0) return 2;
    return 0;
}
