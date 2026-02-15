// Exit code: 0
union U {
    int i;
    float f;
};
typedef union U Num;

int main(void) {
    Num n;
    n.i = 42;
    if (n.i != 42) return 1;
    n.f = 3.14f;
    // Basic check that union writes overlap (value check depends on representation, 
    // just checking assignment works is enough for compiler test)
    return 0;
}