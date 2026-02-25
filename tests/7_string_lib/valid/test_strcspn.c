// Exit code: 0
#include <string.h>

int test_none() { return strcspn("abc", "xyz") == 3 ? 0 : 1; }
int test_partial() { return strcspn("abqc", "q") == 2 ? 0 : 1; }
int test_start() { return strcspn("abc", "a") == 0 ? 0 : 1; }

int main(void) {
    if (test_none() != 0) return 1;
    if (test_partial() != 0) return 2;
    if (test_start() != 0) return 3;
    return 0;
}
