// Exit code: 0
#include "struct_large_test.h"
int main() {
    struct S s = {{1, 2, 3, 4, 5, 6, 7, 8}};
    int v1 = check(1, s);
    if(v1 != 8) return 1;
    return 0;
}
