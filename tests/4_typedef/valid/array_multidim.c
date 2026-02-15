// Exit code: 0
typedef int Matrix[2][2];

int main(void) {
    Matrix m = {{1, 2}, {3, 4}};
    if (m[1][0] != 3) return 1;
    return 0;
}