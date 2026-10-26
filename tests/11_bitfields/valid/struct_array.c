/* Valid: Arrays of structs containing bitfields */
struct S {
    unsigned int a : 4;
    unsigned int b : 4;
};

int main(void) {
    struct S arr[3];
    arr[0].a = 1;
    arr[1].b = 2;
    arr[2].a = 15;

    if (arr[0].a != 1) return 1;
    if (arr[1].b != 2) return 2;
    if (arr[2].a != 15) return 3;
    return 0;
}
