// Exit code: 0
typedef int T;

int main(void) {
    T out = 1;
    {
        typedef float T;
        T in = 1.5f;
        if (in < 1.4) return 1;
    }
    if (out != 1) return 2;
    return 0;
}