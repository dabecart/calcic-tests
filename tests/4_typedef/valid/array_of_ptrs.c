// Exit code: 0
typedef int * IntPtr;
typedef IntPtr PtrArray[3];

int main(void) {
    int a=1;
    int b=2;
    int c=3;
    PtrArray arr = {&a, &b, &c};
    if (*arr[1] != 2) return 1;
    return 0;
}