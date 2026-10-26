#include "common.h"

int server_check(void) {
    struct AbiStruct s = create_struct(3, 7, 200);
    return verify_struct(s);
}
