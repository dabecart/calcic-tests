// Exit code: 0
typedef int * Ptr;
// 'const Ptr' makes the POINTER const, not the int.
int main(void) {
    int a = 1;
    int b = 2;
    const Ptr p = &a; 
    *p = 3;
    if (a != 3) return 1;
    return 0;
}