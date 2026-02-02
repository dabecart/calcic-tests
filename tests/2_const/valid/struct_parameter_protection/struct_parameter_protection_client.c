// Exit code: 0

#include "params.h"
int main() {
    struct Config my_conf = {1, 100};

    if(!check_config(&my_conf)) {
        return 1;
    }

    return 0;
}