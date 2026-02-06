// Exit code: 0
/* Test: Pointer to enum variable. */
enum E { A = 10 };
int main() {
    enum E val = A;
    enum E *p = &val;
    if (*p != 10) return 1;
    *p = (enum E)20; // cast for safety/clarity, though int compatible
    if (val != 20) return 2;
    return 0;
}