// Exit code: 0
#include <string.h>

/* Should find the LAST occurrence */
int test_found() {
    char s[6]="abcab"; 
    return strrchr(s, 'b') == &s[4] ? 0 : 1; 
}

int test_not_found() { 
    return strrchr("abc", 'd') == NULL ? 0 : 1; 
}

int test_null_term() { 
    char s[4]="abc"; 
    return strrchr(s, '\0') == &s[3] ? 0 : 1; 
}

int main(void) {
    if (test_found() != 0) return 1;
    if (test_not_found() != 0) return 2;
    if (test_null_term() != 0) return 3;
    return 0;
}
