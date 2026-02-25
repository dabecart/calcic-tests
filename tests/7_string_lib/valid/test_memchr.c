// Exit code: 0
#include <string.h>

int test_found() { 
    char s[4] = "abc"; 
    return memchr(s, 'b', 3) == &s[1] ? 0 : 1; 
}

int test_not_found() { 
    return memchr("abc", 'd', 3) == NULL ? 0 : 1; 
}

int test_zero_len() { 
    return memchr("abc", 'a', 0) == NULL ? 0 : 1; 
}

int main(void) {
    if (test_found() != 0) return 1;
    if (test_not_found() != 0) return 2;
    if (test_zero_len() != 0) return 3;
    return 0;
}
