/* Test: Duplicate enumerator name in same scope. */
enum E1 { A };
enum E2 { A }; // ERROR: Redeclaration of enumerator 'A'
int main() { return 0; }