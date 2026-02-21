// Exit code: 0
#include "struct_unaligned_test.h"
int main() {
    struct S s = {1, 2, 3};
    int v1 = check(1, s);
    if(v1 != 1) return 1;
    return 0;
}
