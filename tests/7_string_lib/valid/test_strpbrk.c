// Exit code: 0
#include <string.h>

int test_match() { 
    char s[6] = "hello"; 
    return strpbrk(s, "aeiou") == &s[1] ? 0 : 1; 
}

int test_no_match() { 
    return strpbrk("xyz", "aeiou") == NULL ? 0 : 1; 
}

int main(void) {
    if (test_match() != 0) return 1;
    if (test_no_match() != 0) return 2;
    return 0;
}
