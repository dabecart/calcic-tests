/* Test: Redefining enum tag inside struct scope in a conflicting way. */
enum E { A };
struct S {
    int enum E { B }; // SYNTAX ERROR: Cannot use 'int' and 'enum' specifiers together like this
};
int main() { return 0; }