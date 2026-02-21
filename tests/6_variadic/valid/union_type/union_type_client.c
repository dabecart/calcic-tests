// Exit code: 0
#include "union_type_test.h"
int main() {
    union U u; 
    u.a = 77;
    int v1 = check(1, u);
    if(v1 != 77) return 1;
    return 0;
}
