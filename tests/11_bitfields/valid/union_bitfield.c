/* Valid: Bitfields inside unions */
union U {
    struct {
        unsigned int a : 4;
        unsigned int b : 4;
    } s;
    unsigned char raw;
};

int main(void) {
    union U u;
    u.s.a = 0x3;
    u.s.b = 0x5;
    if (u.s.a != 3 || u.s.b != 5) return 1;
    return 0;
}
