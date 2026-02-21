// Exit code: 0
#include "simple_floats_test.h"
int main() {
    int v1 = check(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    if(v1 != 1) return 1;
    return 0;
}
