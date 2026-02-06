/* Test: Malformed hex literal in enum. */
enum E { A = 0xG1 }; // LEXICAL ERROR: Invalid hex literal
int main() { return 0; }