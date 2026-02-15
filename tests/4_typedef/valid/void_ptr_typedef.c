// Exit code: 0
typedef void * VoidPtr;
int main(void) {
    int x = 10;
    VoidPtr vp = &x;
    if (*(int*)vp != 10) return 1;
    return 0;
}