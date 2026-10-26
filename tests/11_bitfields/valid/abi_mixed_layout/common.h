#ifndef COMMON_H
#define COMMON_H

struct MixedAbi {
    unsigned char a : 3;
    unsigned short b : 9;
    unsigned int c : 12;
};

struct MixedAbi modify_mixed(struct MixedAbi m);

#endif
