// Exit code: 0
typedef int Array5[5];

int main(void) {
    Array5 a = {1, 2, 3, 4, 5};
    if (a[0] != 1) return 1;
    if (a[4] != 5) return 2;
    if (sizeof(a) != 5 * sizeof(int)) return 3;
    return 0;
}