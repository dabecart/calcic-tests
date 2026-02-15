// Exit code: 0
typedef int T1;
typedef T1 T2;
typedef T2 T3;

int main(void) {
    T3 x = 50;
    if (x != 50) return 1;
    return 0;
}