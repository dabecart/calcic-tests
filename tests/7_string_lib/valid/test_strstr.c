// Exit code: 0
#include <string.h>

int test_found() { 
    char s[12] = "hello world"; 
    return strstr(s, "lo") == &s[3] ? 0 : 1; 
}

int test_not_found() { 
    return strstr("hello", "xyz") == NULL ? 0 : 1; 
}

/* Standard states: if needle is empty, return haystack pointer */
int test_empty_needle() { 
    char s[7] = "hello"; 
    return strstr(s, "") == s ? 0 : 1; 
}

int main(void) {
    if (test_found() != 0) return 1;
    if (test_not_found() != 0) return 2;
    if (test_empty_needle() != 0) return 3;
    return 0;
}
