// Exit code: 0
#include <string.h>

int test_basic() { return strlen("hello") == 5 ? 0 : 1; }
int test_empty() { return strlen("") == 0 ? 0 : 1; }

int main(void) {
    if (test_basic() != 0) return 1;
    if (test_empty() != 0) return 2;
    return 0;
}
