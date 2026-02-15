// Exit code: 0
typedef int * Ptr;
// 'const Ptr' makes the POINTER const, not the int.
int main(void) {
    int a = 1;
    int b = 2;
    const Ptr p = &a; 
    p = &b; // Not allowed
    if (p != &b) return 1;
    return 0;
}