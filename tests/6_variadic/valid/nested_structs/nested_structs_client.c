// Exit code: 0
#include "nested_structs_test.h"
int main() {
    struct B b = {{1}, 2.0};
    int v1 = check(1, b);
    if(v1 != 1) return 1;
    return 0;
}
