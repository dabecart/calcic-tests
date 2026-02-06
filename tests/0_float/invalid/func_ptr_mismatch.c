/* Error: Incompatible function pointer assignment */
void func(int x) {}
int main() {
    void (*fp)(float) = func; 
    return 0;
}