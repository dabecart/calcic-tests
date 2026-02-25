// Exit code: 0
#include <string.h>

int test_basic() {
    char d[5] = "xxxx";
    memset(d, 'a', 3);
    return (d[0]=='a' && d[1]=='a' && d[2]=='a' && d[3]=='x') ? 0 : 1;
}

int test_zero_bytes() {
    char d[5] = "xxxx";
    memset(d, 'a', 0);
    return strcmp(d, "xxxx") == 0 ? 0 : 1;
}

int main(void) {
    if (test_basic() != 0) return 1;
    if (test_zero_bytes() != 0) return 2;
    return 0;
}
