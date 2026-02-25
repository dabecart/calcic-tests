// Exit code: 0
#include <string.h>

/* Test standard equality */
int test_eq() { 
    return memcmp("abc", "abc", 3) == 0 ? 0 : 1; 
}

/* Test less than / greater than */
int test_lt() { 
    return memcmp("aba", "abc", 3) < 0 ? 0 : 1; 
}

int test_gt() {
    return memcmp("abc", "aba", 3) > 0 ? 0 : 1; 
}

/* Standard requires memcmp to use unsigned char for evaluation */
int test_unsigned() {
    char a[2] = {(char)250}; /* 250 as unsigned is greater than 10 */
    char b[2] = {10};
    return memcmp(a, b, 1) > 0 ? 0 : 1; 
}

/* Test zero length comparison */
int test_zero() { return memcmp("a", "b", 0) == 0 ? 0 : 1; }

int main(void) {
    if (test_eq() != 0) return 1;
    if (test_lt() != 0) return 2;
    if (test_gt() != 0) return 3;
    if (test_unsigned() != 0) return 4;
    if (test_zero() != 0) return 5;
    return 0;
}
