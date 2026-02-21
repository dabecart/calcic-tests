// Exit code: 0
#include "pointers_test.h"
int main() {
    char x = 0;
    int v1 = check(2, (void*)&x, &x);
    if(v1 != 1) return 1;
    return 0;
}
