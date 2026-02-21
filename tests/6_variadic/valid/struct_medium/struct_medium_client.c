// Exit code: 0
#include "struct_medium_test.h"
int main() {
    struct S s = {1, 2, 3, 4};
    int v1 = check(1, s);
    if(v1 != 5) return 1;
    return 0;
}
