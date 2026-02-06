/* Test: Global enum variable initialized with non-constant. */
enum E { A };
int x = 5;
enum E e = x; // ERROR: Initializer element is not constant (for global/static)
int main() { return 0; }