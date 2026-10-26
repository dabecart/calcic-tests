#include "common.h"

int test_outer(struct OuterAbi out) {
    if (out.in.p != 3) return 1;
    if (out.in.q != 40) return 2;
    if (out.r != 10) return 3;
    return 0;
}

int main(void) {
    extern int server_runner(void);
    return server_runner();
}
