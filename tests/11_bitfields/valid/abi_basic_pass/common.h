#ifndef COMMON_H
#define COMMON_H

struct AbiStruct {
    unsigned int x : 4;
    unsigned int y : 4;
    unsigned int z : 8;
};

int verify_struct(struct AbiStruct s);
struct AbiStruct create_struct(unsigned int x, unsigned int y, unsigned int z);

#endif
