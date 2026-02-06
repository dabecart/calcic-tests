/* Test: Trying to assign a value to an enum constant. */
enum E { A = 1 };
int main() {
    A = 2; // ERROR: Expression is not assignable (lvalue required)
    return 0;
}