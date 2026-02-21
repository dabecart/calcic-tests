// Exit code: 0
#include "promotions_test.h"
int main() {
    char a = 1; short b = 2; float c = 3.0f;
    int v1 = check(3, a, b, c);
    if(v1 != 1) return 1;
    return 0;
}
