// Exit code: 0
#include <string.h>

int test_full() { 
    return strspn("abc", "cba") == 3 ? 0 : 1; 
}

int test_partial() { 
    return strspn("abqc", "cba") == 2 ? 0 : 1; 
}

int test_none() { 
    return strspn("xyz", "cba") == 0 ? 0 : 1; 
}

int main(void) {
    if (test_full() != 0) return 1;
    if (test_partial() != 0) return 2;
    if (test_none() != 0) return 3;
    return 0;
}
