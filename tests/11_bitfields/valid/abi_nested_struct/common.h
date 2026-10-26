#ifndef COMMON_H
#define COMMON_H

struct Inner {
    unsigned int p : 2;
    unsigned int q : 6;
};

struct OuterAbi {
    struct Inner in;
    unsigned int r : 4;
};

int test_outer(struct OuterAbi out);

#endif
