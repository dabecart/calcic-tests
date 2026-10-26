#include "common.h"

int server_test(void) {
    struct MixedAbi m;
    m.a = 5;
    m.b = 300;
    m.c = 2000;
    
    struct MixedAbi res = modify_mixed(m);
    if (res.a != 6) return 1;
    if (res.b != 301) return 2;
    if (res.c != 2001) return 3;
    return 0;
}
