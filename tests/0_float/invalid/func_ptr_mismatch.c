/* Error: Incompatible function pointer assignment */
void func(int x) {}
void test() {
    void (*fp)(float) = func; 
}