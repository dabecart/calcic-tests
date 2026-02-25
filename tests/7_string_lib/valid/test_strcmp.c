// Exit code: 0
#include <string.h>

int test_eq() { return strcmp("abc", "abc") == 0 ? 0 : 1; }
int test_lt() { return strcmp("aba", "abc") < 0 ? 0 : 1; }
int test_gt() { return strcmp("abc", "aba") > 0 ? 0 : 1; }
int test_empty() { return strcmp("", "a") < 0 ? 0 : 1; }

int main(void) {
    if (test_eq() != 0) return 1;
    if (test_lt() != 0) return 2;
    if (test_gt() != 0) return 3;
    if (test_empty() != 0) return 4;
    return 0;
}
