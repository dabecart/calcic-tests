// Exit code: 0
typedef int* IntPtr;

int main(void) {
    int val = 100;
    IntPtr p = &val;
    if (*p != 100) return 1;
    *p = 200;
    if (val != 200) return 2;
    return 0;
}