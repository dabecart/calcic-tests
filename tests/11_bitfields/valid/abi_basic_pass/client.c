#include "common.h"

struct AbiStruct create_struct(unsigned int x, unsigned int y, unsigned int z) {
    struct AbiStruct s;
    s.x = x;
    s.y = y;
    s.z = z;
    return s;
}

int verify_struct(struct AbiStruct s) {
    if (s.x != 3) return 1;
    if (s.y != 7) return 2;
    if (s.z != 200) return 3;
    return 0;
}

int main(void) {
    extern int server_check(void);
    return server_check();
}
