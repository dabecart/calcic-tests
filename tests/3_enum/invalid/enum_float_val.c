/* Test: Enum constant defined with floating point literal. */
enum E {
    VAL = 3.14 // ERROR: Enumerator value for 'VAL' is not an integer constant
};
int main() { return 0; }