// Exit code: 0
#include <string.h>

int test_found() { 
    char s[6] = "abcab"; 
    return strchr(s, 'b') == &s[1] ? 0 : 1; 
}

int test_not_found() { 
    return strchr("abc", 'd') == NULL ? 0 : 1; 
}

/* Standard requires finding the terminating null byte */
int test_null_term() { 
    char s[4] = "abc"; 
    return strchr(s, '\0') == &s[3] ? 0 : 1; 
}

int main(void) {
    if (test_found() != 0) return 1;
    if (test_not_found() != 0) return 2;
    if (test_null_term() != 0) return 3;
    return 0;
}
