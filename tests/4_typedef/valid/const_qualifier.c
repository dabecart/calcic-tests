// Exit code: 0
typedef int T;
int main(void) {
    const T x = 10;
    // x = 11; // Should fail compilation if uncommented
    if (x != 10) return 1;
    return 0;
}