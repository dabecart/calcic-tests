// Exit code: 0
struct S { 
    int a, b, c, d; 
};

int main() {
    struct S test = {1, 2, 3, 4};
    if(test.a != 1 || test.b != 2 || test.c != 3 || test.d != 4) return 1;
    return 0;
}