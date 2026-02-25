// Exit code: 0
#include <string.h>

/* Uses LC_COLLATE locale, basic C locale functions identically to strcmp here */
int test_basic() { 
    return strcoll("abc", "abc") == 0 ? 0 : 1; 
}

int main(void) {
    if (test_basic() != 0) return 1;
    return 0;
}
