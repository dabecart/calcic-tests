/* Test: Empty enum declaration without variables (Constraint violation in strict C). */
enum Empty { }; // ERROR: Enums must have at least one enumerator
int main() { return 0; }