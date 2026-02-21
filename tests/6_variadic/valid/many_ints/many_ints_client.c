// Exit code: 0
#include "many_ints_test.h"
int main() {
    int v1 = check(8, 1, 2, 3, 4, 5, 6, 7, 8);
    if(v1 != 36) return 1;
    return 0;
}
