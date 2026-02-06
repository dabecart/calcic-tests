/* Test: Initializing union with incompatible enum pointer. */
enum E { A };
union U { int i; float f; };
int main() {
    enum E *p = 0;
    union U u = { p }; // ERROR: Initialize union with incompatible pointer type
    return 0;
}