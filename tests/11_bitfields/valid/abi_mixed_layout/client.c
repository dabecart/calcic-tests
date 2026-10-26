#include "common.h"

struct MixedAbi modify_mixed(struct MixedAbi m) {
    m.a += 1;
    m.b += 1;
    m.c += 1;
    return m;
}

int main(void) {
    extern int server_test(void);
    return server_test();
}
