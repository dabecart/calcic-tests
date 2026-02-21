// Exit code: 0
#include "pass_valist_test.h"
int main() {
    int v1 = check(1, 99);
    if(v1 != 99) return 1;
    return 0;
}
