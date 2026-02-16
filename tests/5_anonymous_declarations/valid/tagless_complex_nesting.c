// Exit code: 0
// Deep nesting of tagless structs/unions and arrays.

typedef struct {
    int type_code;
    /* Anonymous type inside a named member */
    struct {
        int r;
        int g;
        int b;
    } color;
    /* Array of tagless unions */
    union {
        unsigned char bytes[4];
        unsigned int val;
    } data[2];
} Pixel;

int main(void) {
    Pixel p;
    
    p.type_code = 1;
    p.color.r = 255;
    p.color.g = 0;
    p.color.b = 0;

    if (p.color.r != 255) return 10;

    /* Interaction with arrays of nested tagless unions */
    p.data[0].val = 0xAABBCCDD;
    p.data[1].val = 0x11223344;

    if (p.data[0].val != 0xAABBCCDD) return 11;
    if (p.data[1].val != 0x11223344) return 12;

    /* Pointer to nested member */
    unsigned int *uptr = &p.data[0].val;
    if (*uptr != 0xAABBCCDD) return 13;

    return 0;
}
