// Exit code: 0
union U { 
    int a, b, c, d; 
    double x, y;
};

int main() {
    union U test = {1};
    if(test.a != 1 || test.b != 1 || test.c != 1 || test.d != 1) return 1;
    return 0;
}