// Exit code: 0
typedef int I;
typedef float F;

int main(void) {
    F f = 5.9;
    I i1 = (I)f;
    I i2 = f;

    if (i1 != 5) return 1;
    if (i2 != 5) return 2;

    return 0;
}