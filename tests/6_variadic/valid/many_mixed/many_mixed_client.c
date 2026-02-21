// Exit code: 0
#include "many_mixed_test.h"
int main() {
    int v1 = check(15, 1,1,1,1,1,1, 1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0, 10);
    if(v1 != 24) return 1;
    return 0;
}
