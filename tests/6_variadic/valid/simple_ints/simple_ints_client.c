// Exit code: 0
#include "simple_ints_test.h"
int main() {
    int v1 = check(3, 10, 20, 30);
    if(v1 != 60) return 1;
    int v2 = check(2, -5, 5);
    if(v2 != 0) return 2;
    return 0;
}
