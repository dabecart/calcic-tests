/* Test: Enum constant defined with string literal. */
enum E {
    VAL = "Error" // ERROR: Enumerator value is not an integer constant
};
int main() { return 0; }