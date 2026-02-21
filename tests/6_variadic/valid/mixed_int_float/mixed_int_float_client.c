// Exit code: 0
#include "mixed_int_float_test.h"
int main() {
    int v1 = check(3, 1, 2.0, 3);
    if(v1 != 1) return 1;
    return 0;
}
