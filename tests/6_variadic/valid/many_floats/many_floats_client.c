// Exit code: 0
#include "many_floats_test.h"
int main() {
    int v1 = check(10, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
    if(v1 != 1) return 1;
    return 0;
}
