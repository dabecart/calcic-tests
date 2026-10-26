#include "common.h"

int server_runner(void) {
    struct OuterAbi o;
    o.in.p = 3;
    o.in.q = 40;
    o.r = 10;
    return test_outer(o);
}
