/* Cannot take address of register variable in constant expr */
void func() {
    register int a;
    static int *p = &a; 
}
int main() { return 0; }