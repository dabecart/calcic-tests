/* Test: Assigning float pointer to enum pointer. */
enum E { A };
int main() {
    float f = 1.0;
    enum E *p = &f; // ERROR: Incompatible pointer types
    return 0;
}