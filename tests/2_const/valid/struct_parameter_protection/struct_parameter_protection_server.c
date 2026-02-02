#include "params.h"

int check_config(const struct Config *c) {
    int x = c->id; /* Valid */
    int y = c->value;
    // c->value = 5; /* ERROR: If you uncomment this, it must fail compilation */
    return x == 1 && y == 100;
}