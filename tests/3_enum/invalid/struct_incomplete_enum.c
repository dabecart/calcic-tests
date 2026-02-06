/* Test: Using enum before definition inside struct. */
struct S {
    enum E val; // ERROR: Field has incomplete type 'enum E'
};
enum E { A, B };
int main() { return 0; }